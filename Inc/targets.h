#include "main.h"
#include "conf.h"
#include "controller.h"
#include "servos.h"
#include <string.h>

#include "print.h"

#ifndef TARGETS_H
#define TARGETS_H

static bool process_targets = false;

typedef enum {
	MOVE, PICK, PLACE
} TargetType;

typedef struct {
	TargetType type;
	float x;
	float y;
} target;

void addTarget(target target);
void targetsTick(uint8_t dt);

void setProcessTargets(bool enable);

bool isProcessTargets(void);

typedef struct {
	uint32_t size;
	uint32_t write_idx;
	uint32_t read_idx;
	target *data;
} targets_fifo_t;

uint32_t targets_fifo_read(targets_fifo_t *fifo, target *dest, uint32_t n);
uint32_t targets_fifo_write(targets_fifo_t *fifo, target *src, uint32_t n);

#endif
