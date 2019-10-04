
#include "keyb_4x4_ttp229_sm.h"

/******************************************************/

	char DataChar[100];
	uint8_t button_status = 0;

/******************************************************/

void TTP229_start(UART_HandleTypeDef * _d_uart)
{
	char DataChar[100];
	sprintf(DataChar,"\r\nKeyBoard 4x4 over TTP229 v2.0.0\r\nUART1 for debug started on speed 115200\r\n");
	HAL_UART_Transmit(_d_uart, (uint8_t *)DataChar, strlen(DataChar), 100);
	HAL_GPIO_WritePin(SLC_GPIO_Port, SLC_Pin, GPIO_PIN_SET);
}
/******************************************************/

uint8_t TTP229_scan_keyboard ()
{
	uint8_t key_pressed = 0;
	ttp_delay(100);
	for (int i = 0; i<16; i++)
	{
	  HAL_GPIO_WritePin(SLC_GPIO_Port, SLC_Pin, GPIO_PIN_RESET);
	  ttp_delay(5);
	  GPIO_PinState btn_state = HAL_GPIO_ReadPin(SDA_GPIO_Port,SDA_Pin);

	  if (btn_state == 0)
	  {
		  key_pressed = i + 1;
	  }
	  HAL_GPIO_WritePin(SLC_GPIO_Port, SLC_Pin, GPIO_PIN_SET);
	  ttp_delay(5);
	}
	return key_pressed;
}
/******************************************************/

void ttp_delay(uint32_t t)
{
	for (; t; t--)
	{
		__asm("nop");
	}
}
/******************************************************/

uint8_t Get_button_pressed_status (void)
{
	return button_status;
}
/******************************************************/

void Set_button_pressed_status (uint8_t _status)
{
	button_status = _status;
}
/******************************************************/
/******************************************************/
