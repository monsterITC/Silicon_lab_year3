//=========================================================
// src/myProject_8_main.c: generated by Hardware Configurator
//
// This file will be updated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8LB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
// $[Generated Includes]
// [Generated Includes]$
sbit led = P1 ^ 3;
uint8_t i=0;
//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void
SiLabs_Startup (void)
{
  // $[SiLabs Startup]
  // [SiLabs Startup]$
}
void
enable_clock ()
{
  CLKSEL = CLKSEL_CLKDIV__SYSCLK_DIV_8 | CLKSEL_CLKSL__HFOSC0;  //3.0625MHz
}
void
timer_delay ()
{
  CKCON0 = CKCON0_T0M__PRESCALE | CKCON0_SCA__SYSCLK_DIV_48; // clk_control =sysclk/48=63802
  TMOD = TMOD_T0M__MODE1;   // 16 bits mode 1
  TH0 = 0X06;   //hold
  TL0 = 0XC5;  //counting FF
  TCON_TR0 = 1;
  while (TCON_TF0 == 0);
  TCON_TR0 = 0;
  TCON_TF0 = 0;

}
//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int
main (void)
{
  // Call hardware initialization routine
  // enter_DefaultMode_from_RESET ();
  XBR2 |= XBR2_XBARE__ENABLED;
  P1MDOUT |= P1MDOUT_B3__PUSH_PULL;
  enable_clock ();

  while (1)
    {
      led = ~led;   //change state of led  0->1

      timer_delay ();

       //delay 1 second
// $[Generated Run-time code]
// [Generated Run-time code]$
    }
}
