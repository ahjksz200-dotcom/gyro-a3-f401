#include "config.h"

static float integral = 0;
static float prev_error = 0;

void PID_Init(void)
{
    integral = 0;
    prev_error = 0;
}

float PID_Update(float setpoint, float measured)
{
    float error = setpoint - measured;

    integral += error;
    float derivative = error - prev_error;

    prev_error = error;

    return PID_P*error + PID_I*integral + PID_D*derivative;
}
