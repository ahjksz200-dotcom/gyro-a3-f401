#ifndef PWM_OUT_H
#define PWM_OUT_H

#include <stdint.h>

void PWM_OUT_Init(void);
void PWM_OUT_Set(uint8_t ch, uint16_t value);

#endif
