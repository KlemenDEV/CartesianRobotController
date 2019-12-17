#include "main.h"
#include "conf.h"
#include "targets.h"

#include <string.h>

#ifndef COMMUNICATION_H
#define COMMUNICATION_H

void communicationTick(void);

void uartPrint(char *text);
void uartPrintln(char *text);

#endif
