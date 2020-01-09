#include "print.h"

extern UART_HandleTypeDef huart2;

void uartPrint(char *text) {
	HAL_UART_Transmit(&huart2, (uint8_t *) text, strlen(text), 0xFFFF);
}

void uartPrintln(char *text) {
	HAL_UART_Transmit(&huart2, (uint8_t *) text, strlen(text), 0xFFFF);
	char newline[2] = "\r\n";
	HAL_UART_Transmit(&huart2, (uint8_t *) newline, 2, 0xFFFF);
}
