#include "stm32f4xx.h"
#include  "spi.h"
#include  "mpu6500.h"
#include "gpio.h"
#include "delay.h"

void GPIO_Init ( void ) ;
void delay ( volatile uint32_t time ) ;

int main ( void )
{
    SystemInit ( ) ;

    GPIO_Init ( ) ;
    SPI1_Init ( ) ;
    MPU6500_Init ( ) ;

    // Kiểm tra WHO_AM_I
    uint8_t id = MPU6500_ReadReg ( 0x75 ) ;

    // Nếu đúng MPU6500 thì id = 0x70
    trong khi  ( 1 )
    {
        MPU6500_ReadGyro ( ) ;

        // breakpoint tại đây để xem:
        // gyro_x
        // gyro_y
        // gyro_z

        trì hoãn ( 50000 ) ;
    }
}
