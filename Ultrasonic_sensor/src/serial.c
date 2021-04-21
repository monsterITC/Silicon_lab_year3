/*
 * serial.c
 *
 *  Created on: Apr 19, 2021
 *      Author: tadashi
 */
#include "serial.h"


void Uart_timer(){

  CKCON0 = CKCON0_T1M__SYSCLK;
  XBR0 |= XBR0_URT0E__ENABLED;
  P0MDOUT |= P0MDOUT_B4__PUSH_PULL;
  TMOD =TMOD_T1M__MODE2;
  TL1=0X96;
  TH1=0X96;
  TCON_TR1=1;

}

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

