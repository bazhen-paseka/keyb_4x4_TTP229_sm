#ifndef KEYBOARD_4X4_TTP229_SM_H_INCLUDED
#define KEYBOARD_4X4_TTP229_SM_H_INCLUDED
/***********************************/

	#include <string.h>
	#include <stdio.h>
	#include "main.h"

/***********************************/

void TTP229_start(UART_HandleTypeDef * _d_uart);
uint8_t TTP229_scan_keyboard();
uint8_t Get_button_pressed_status (void);
void Set_button_pressed_status (uint8_t);

void ttp_delay(uint32_t t);

#endif 	//	KEYBOARD_4X4_TTP229_SM_H_INCLUDED
