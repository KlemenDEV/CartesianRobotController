#include "main.h"
#include "conf.h"
#include "controller.h"
#include <string.h>

#ifndef TARGETS_H
#define TARGETS_H

typedef enum {
	MOVE, PICK, PLACE
} TargetType;

typedef struct {
	TargetType type;
	float x;
	float y;
} target;

void addTarget(target target);
void targetsTick(void);

typedef struct {
	uint32_t size;
	uint32_t write_idx;
	uint32_t read_idx;
	target *data;
} fifo_t;

uint32_t targets_fifo_read(fifo_t *fifo, target *dest, uint32_t n);
uint32_t targets_fifo_write(fifo_t *fifo, target *src, uint32_t n);

#endif
