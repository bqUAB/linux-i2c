#include <stdio.h>
#include "i2c.h"


int main() {
  I2cBus i2c_2(2);
  uint8_t value = i2c_2.ReadFromMem(0x68, 0x75) ; //MPU
  uint8_t value2 = i2c_2.ReadFromMem(0x1b, 0x03); //DLP
  printf("The value read is: 0x%X for the MPU and 0x%X for the DLP\n", value,value2);
  return 0;
}
