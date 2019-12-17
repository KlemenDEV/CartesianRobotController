#include "communication.h"

extern UART_HandleTypeDef huart2;

void communicationTick(void) {
	uint8_t datain;
	HAL_StatusTypeDef result = HAL_UART_Receive(&huart2, &datain, 1, 1);
	if(result != HAL_TIMEOUT) {
		if(datain == 0x02) { // inbound point data command (we expect 8 bytes of data payload)
			float x = 0, y = 0;
			uint8_t point[4];
			// receive X point
			result = HAL_UART_Receive(&huart2, point, 4, 10);
			if(result != HAL_TIMEOUT) {
				memcpy(&x, &point, sizeof(x));
				// receive Y point
				result = HAL_UART_Receive(&huart2, point, 4, 10);
				if(result != HAL_TIMEOUT) {
					memcpy(&y, &point, sizeof(y));
					
					// add move target
					target target_point;
					target_point.type = MOVE;
					target_point.x = x;
					target_point.y = y;
					addTarget(target_point);
				}
			}
		} else if(datain == 0x03) { // start processing targets command (no data payload)
			setProcessTargets(true);
		} else if(datain == 0x04) { // stop processing targets command (no data payload)
			setProcessTargets(false);
		} else if(datain == 0xFF) { // emergency stop (no data payload)
			setSpeedX(0);
			setSpeedY(0);
			disableMotors();
			setProcessTargets(false);
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
