/*
 * serial.h
 *
 *  Created on: Apr 19, 2021
 *      Author: tadashi
 */

#ifndef INC_SERIAL_H_
#define INC_SERIAL_H_
#include <SI_EFM8LB1_Register_Enums.h>

void Uart_timer();
void put_char(char c);
void put_string(char* str);


#endif /* INC_SERIAL_H_ */
