#include "fifo.h"

uint32_t fifo_read(fifo_t *fifo, void *dest, uint32_t n){
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

uint32_t fifo_write(fifo_t *fifo, void *src, uint32_t n){
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
