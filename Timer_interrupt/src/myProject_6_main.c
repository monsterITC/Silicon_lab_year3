//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8LB1_Register_Enums.h>                // SFR declarations
#include <STDIO.H>

uint32_t volatile msTicks = 0;

//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup (void)
{
  // Disable the watchdog here
  WDTCN = 0xDE;
  WDTCN = 0xAD;
}

/* Interrupt service routine **************************************************/
SI_INTERRUPT(TIMER0_ISR, TIMER0_IRQn)
{
  msTicks += 10; // increase every 10 ms
  // reload timer value
  TH0 = 0x10;
  TL0 = 0xBE;
  // clear interrupt flag
  TCON_TF0 = 0;
}

/* Initialization functions ***************************************************/
void SYSCLK_Init()
{
  /* set up SYSCLK to 24.5 MHz */
  CLKSEL = CLKSEL_CLKDIV__SYSCLK_DIV_1 | CLKSEL_CLKSL__HFOSC0;
  while ((CLKSEL & CLKSEL_DIVRDY__BMASK) != CLKSEL_DIVRDY__READY);
}

void XBAR_Init()
{
  /* set up crossbar */
  XBR2 |= XBR2_XBARE__ENABLED; // enable crossbar
  // skip P0.0 - P0.3, P0.6 - P0.7, P1.0 - P1.2
  P0SKIP = 0xCF; // 0b1100 1111
  P1SKIP = 0x07; // 0b0000 0111
  // enable output compare CEX0 and UART0
  XBR0 |= XBR0_URT0E__ENABLED;
  XBR1 |= XBR1_PCA0ME__CEX0;

  // set up UART0 TX pin (P0.4) as push-pull
  P0MDOUT |= P0MDOUT_B4__PUSH_PULL;

  // set up P1.3 as push-pull
 // P1MDOUT |= P1MDOUT_B3__PUSH_PULL;
  P1MDOUT |= P1MDOUT_B3__PUSH_PULL;
}

void PWM_Init()
{
  /* setup 8-bit PWM on CEX0 */
  PCA0CPM0 |= PCA0CPM0_PWM__ENABLED;
  // write pwm to autoreload register
  PCA0CPH0 = 0;
  // start PCA
  PCA0CN0 |= PCA0CN0_CR__RUN;
}

void TIMER01_Init()
{
  // set Timer0 clock prescaler to SYSCLK/4 = 6125000Hz
  // set Timer1 clock to SYSCLK = 24500000HZ
  CKCON0 = CKCON0_SCA__SYSCLK_DIV_4 | CKCON0_T1M__SYSCLK;

  // set Timer0 mode to 16-bit timer and Timer1 to 8-bit auto reload
  TMOD = TMOD_T0M__MODE1 | TMOD_T1M__MODE2;
  /* set up Timer0 interrupt for 10ms */
  // write reload value to TH0 and TL0
  // TH0:TL0 = 65536 - F_CLK/F_DESIRED
  //         = 65536 - 6125000Hz/100Hz = 4286 or 0x10BE
  TH0 = 0x10;
  TL0 = 0xBE;

  // set up counter and reload value for Timer1
  // this results in UART0 frequency of 230400Hz
  // or baudrate of 115200 bps
  // baudrate = 1/2 * SYSCLK/(256 - PRESCALER)
  // PRESCALER = 256 - 1/2 * SYSCLK/baurate = 150 or 0x96
  TL1 = 0x96;
  TH1 = 0x96;

  // enable Timer0 overflow interrupt then run the timer
  IE_ET0 = 1;
  TCON_TR0 = 1;
  TCON_TR1 = 1;
}

void UART0_Init()
{
  // configure this function if UART interrupt and/or 9-bit mode is required
  // otherwise, you can leave it blank
}


/* User-defined functions *****************************************************/
void put_char(char c)
{
  SBUF0 = c; // write character to buffer
  while (!SCON0_TI); // wait for Tx to be complete
  SCON0_TI = 0; // clear Tx flag
}

void put_string(char* str)
{
  // send character until null-termination is found
  while (*str != '\x0')
  {
    put_char(*(str++));
  }
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
// Note: the software watchdog timer is not disabled by default in this
// example, so a long-running program will reset periodically unless
// the timer is disabled or your program periodically writes to it.
//
// Review the "Watchdog Timer" section under the part family's datasheet
// for details. To find the datasheet, select your part in the
// Simplicity Launcher and click on "Data Sheet".
//-----------------------------------------------------------------------------
uint32_t t0_last, t1_last, t2_last;

const uint16_t dt0 = 100;
const uint16_t dt1 = 1000;
const uint16_t dt2 = 50;
uint8_t pwm_val = 0;
int8_t pwm_dir = 10;

bit btn_now = 1;
bit btn_last = 1;

char xdata msg[64];

int main (void)
{
  /* device init */
  SYSCLK_Init();
  XBAR_Init();
  PWM_Init();
  TIMER01_Init();
  UART0_Init();

  /* enable all interrupt */
  IE_EA = 1;

  t0_last = msTicks;
  t1_last = msTicks;
  t2_last = msTicks;

  put_string("------ Application started ------\n");
  while (1) {
    /* task scheduling */
    if (msTicks - t0_last >= dt0)
    {
      t0_last = msTicks;
      /* breathing LED */
      if (pwm_val == 0) pwm_dir = 10;
      else if (pwm_val == 250) pwm_dir = -10;
      pwm_val +=pwm_dir;
      PCA0CPH0 = pwm_val;
    }

    if (msTicks - t1_last >= dt1)
    {
      t1_last = msTicks;
      /* print runtime every 1000 ms */
      sprintf(msg, "Runtime: %lu ms\n", msTicks);
      put_string(msg);
    }

    if (msTicks - t2_last >= dt2)
    {
      t2_last = msTicks;
      btn_now = P1_B4;
      if (btn_now == 0 && btn_last == 1) // falling edge
      {
        /* button press event */
        sprintf(msg, "Button is pressed at %lu ms\n", msTicks);
        put_string(msg);
      }
      btn_last = btn_now;
    }
  }                             // Spin forever
}
