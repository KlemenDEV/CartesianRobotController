#include "communication.h"

extern UART_HandleTypeDef huart2;

static HAL_StatusTypeDef result = HAL_OK;

void communicationTick(void) {
	if(isProcessTargets())
		return;
	
	if(!(result == HAL_OK || result == HAL_TIMEOUT))
		return;
	
	uint8_t datain;
	
	HAL_StatusTypeDef result = HAL_UART_Receive(&huart2, &datain, 1, 10);
	if(result == HAL_OK) {
		if(datain == 0x02) { // inbound point data command (we expect 8 bytes of data payload)
			float x = 0, y = 0;
			uint8_t point[4];
			// receive X point
			
			result = HAL_UART_Receive(&huart2, point, 4, 50);
			if(result == HAL_OK) {
				memcpy(&x, &point, sizeof(x));
				// receive Y point
				result = HAL_UART_Receive(&huart2, point, 4, 50);
				if(result == HAL_OK) {
					memcpy(&y, &point, sizeof(y));
					
					// add move target
					target target_point;
					target_point.type = MOVE;
					target_point.x = x;
					target_point.y = y;
					addTarget(target_point);
					
					uartPrint("Received point ");
					char buff[64];
					sprintf(buff, "%f", x);
					uartPrint(buff);
					uartPrint(" x ");
					sprintf(buff, "%f", y);
					uartPrintln(buff);
					
				}
			}
		} else if(datain == 0x03) { // start processing targets command (no data payload)
			setProcessTargets(true);
		} else if(datain == 0x04) { // stop processing targets command (no data payload)
			setProcessTargets(false);
		} else if(datain == 0x0F) { // emergency stop (no data payload)
			disableMotors();
			setProcessTargets(false);
		}
	}
}
