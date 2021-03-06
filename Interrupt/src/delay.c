/*
 * delay.c
 *
 *  Created on: Apr 19, 2021
 *      Author: tadashi
 */


#include "delay.h"


void delay_ms(uint32_t t){
  uint32_t count=0;
 // CKCON0 =CKCON0_T0M__PRESCALE | CKCON0_SCA__SYSCLK_DIV_48;
  TMOD |= TMOD_T0M__MODE1;
  TH0=0XFE;
  TL0=0X01;
  TCON_TR0=1;
  while(1){
      if(TCON_TF0==1){
          count++;
          TCON_TF0=0;
          TH0=0XFE;
          TL0=0X01;
          //TCON_TR0=1;
      }
      if(count>=t){
          break;
      }
  }
  TCON_TF0=0;
 // TCON_TR0=0;
}
