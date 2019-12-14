#include "communication.h"

extern UART_HandleTypeDef huart2;

void communicationTick(void) {
	char buffer;
	HAL_StatusTypeDef result = HAL_UART_Receive(&huart2, (uint8_t*) &buffer, 1, 1);
	if(result != HAL_TIMEOUT) {
		if(buffer == 0x02) { // StartOfText
			
		} else if(buffer == 0x03) { //EndOfText
			
		}
	}
}

void uartPrint(char *text) {
	HAL_UART_Transmit(&huart2, (uint8_t *) text, strlen(text), 10);
}

void uartPrintln(char *text) {
	HAL_UART_Transmit(&huart2, (uint8_t *) text, strlen(text), 10);
	char newline[2] = "\r\n";
	HAL_UART_Transmit(&huart2, (uint8_t *) newline, 2, 10);
}
