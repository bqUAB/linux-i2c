#include <stdio.h>
#include "i2c.h"


int main() {
  I2cBus i2c_2(2);
  
  int valor[126]={0}; // valor del registro
  uint8_t value = i2c_2.ReadFromMem(0x68, 0x75) ; //MPU
  uint8_t value2 = i2c_2.ReadFromMem(0x1b, 0x03); //DLP
  printf("The value read is: 0x%X for the MPU and 0x%X for the DLP\n", value,value2);

  for (int j=0;j<126;j++){
  	valor[j]= i2c_2.ReadFromMem(0x68, j);
  	printf("The value read is:0x%d\n", valor[j]);

  }
  return 0;
}
