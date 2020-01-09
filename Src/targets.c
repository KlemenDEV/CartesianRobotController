#include "targets.h"

#define BUFFER_SIZE 256
target target_buffer[BUFFER_SIZE];
static targets_fifo_t targets_fifo = {BUFFER_SIZE, 0, 0, target_buffer};

bool isProcessTargets(void) {
	return process_targets;
}

void targetsTick(void) {
	if(!process_targets)
		return;
	
	if(getStatus() == IDLE) { // tool not moving, next action
		target *action;
		uint32_t num = targets_fifo_read(&targets_fifo, action, 1);
		if(num > 0) {
			if(action->type == MOVE) {
				moveL(action->x, action->y);
				uartPrintln("Processing next MOVE action");
			} else if(action->type == PICK) {
				setServoPosition(0, 0);
			} else if(action->type == PLACE) {
				setServoPosition(0, 90);
			}
		} else {
			setProcessTargets(false);
		}
	}
}

void addTarget(target _target) {
	targets_fifo_write(&targets_fifo, &_target, 1);
}

void setProcessTargets(bool enable) {
	process_targets = enable;
	if(enable) {
		uartPrintln("Starting processing targets");
	} else {
		uartPrintln("Stopping processing targets");
	}
}

uint32_t targets_fifo_read(targets_fifo_t *fifo, target *dest, uint32_t n){
	uint32_t i = 0;
	for(i = 0; i < n; i++) {
		if(fifo->read_idx == fifo->write_idx) // fifo empty
			break;
		if(fifo->read_idx >= fifo->size - 1)
			fifo->read_idx = 0;
		dest[i] = fifo->data[fifo->read_idx];
		fifo->read_idx++;
	}
	return i;
}

uint32_t targets_fifo_write(targets_fifo_t *fifo, target *src, uint32_t n){
	uint32_t i = 0;
	for(i = 0; i < n; i++){
		uint32_t idx = fifo->write_idx + 1;
		if(idx == fifo->read_idx) // fifo full
			break;
		if(idx == fifo->size)
			idx = 0;
		
		memcpy(&fifo->data[fifo->write_idx], &src[i], sizeof(target));
		
		fifo->write_idx = idx;
	}
	return i;
}
