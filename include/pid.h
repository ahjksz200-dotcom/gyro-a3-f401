#ifndef PID_H
#define PID_H

void PID_Init(void);
float PID_Update(float setpoint, float measured);

#endif
