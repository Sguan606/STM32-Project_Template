#ifndef __SOFTWARE_SPI_H
#define __SOFTWARE_SPI_H


void Software_SPIInit(void);
void SS_W_Set(uint8_t value);
void SCK_W_Set(uint8_t value);
void MOSI_W_Set(uint8_t value);
uint8_t MISO_R_Set(void);
void Software_SPIStart(void);
void Software_SPIStop(void);
uint8_t Software_SwapByte(uint8_t ByteSend);



#endif // !
