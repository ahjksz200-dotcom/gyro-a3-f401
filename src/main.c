#include "stm32f4xx.h"
#include "pwm_in.h"
#include "pwm_out.h"
#include "spi.h"
#include "mpu6500.h"
#include "pid.h"

volatile float angle_roll = 0;

void delay(volatile uint32_t t)
{
    while(t--);
}

int main(void)
{
    SystemInit();

    PWM_IN_Init();
    PWM_OUT_Init();
    SPI1_Init();
    MPU6500_Init();
    PID_Init();

    while (1)
    {
        MPU6500_Read();

        float rc_roll = PWM_IN_Get(0); // channel 1

        float correction = PID_Update(rc_roll, angle_roll);

        PWM_OUT_Set(0, 1500 + correction);

        delay(5000);
    }
}
