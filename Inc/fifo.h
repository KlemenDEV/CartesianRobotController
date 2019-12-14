#include "main.h"

typedef struct {
	uint32_t size;
	uint32_t write_idx;
	uint32_t read_idx;
	void *data;
} fifo_t;

uint32_t fifo_read(fifo_t *fifo, void *dest, uint32_t n);
uint32_t fifo_write(fifo_t *fifo, void *src, uint32_t n);
