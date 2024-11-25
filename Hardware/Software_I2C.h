#ifndef __SOFTWARE_I2C_H
#define __SOFTWARE_I2C_H


void SCL_W_Set(uint16_t value);
void SDA_W_Set(uint16_t value);
uint8_t SDA_R_Set(void);
void Software_I2CInit(void);
void Software_I2CStart(void);
void Software_I2CStop(void);
void Software_I2CSendAck(uint8_t AckBit);
uint8_t Software_I2CReceiveAck(void);
void Software_I2CSendByte(uint8_t Byte);
uint8_t Software_I2CReceiveByte(void);


#endif // !
