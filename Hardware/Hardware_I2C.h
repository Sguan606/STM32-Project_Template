#ifndef __HARDWARE_I2C_H
#define __HARDWARE_I2C_H

uint8_t MPU6050_Address = 0x68;

void Hardware_I2CInit(void);
void I2C_WaitEvent(I2C_TypeDef *I2Cx,uint32_t I2C_EVENNT);
void Software_I2CWriteReg(uint8_t RegAddress,uint8_t Data);
uint8_t Software_I2CReadReg(uint8_t RegAddress);



#endif // !
