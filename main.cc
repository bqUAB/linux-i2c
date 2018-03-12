#include <stdio.h>
#include "i2c.h"


int main() {
  I2cBus i2c_2(2);
  
  int valor[126]={0}; // Valor del registro MPU
  int valor2[255]={0}; //Valor DLP
  uint8_t value = i2c_2.ReadFromMem(0x68, 0x75) ; //MPU
  uint8_t value2 = i2c_2.ReadFromMem(0x1b, 0x03); //DLP
  printf("The value read is: 0x%X for the MPU and 0x%X for the DLP\n", value,value2);

  for (int j=0;j<126;j++){
  	valor[j]= i2c_2.ReadFromMem(0x68, j);
  	printf("The value read of the MPU is:0x%d\n", valor[j]);

  }
   for (int k=0;k<255;k++){
  	valor[k]= i2c_2.ReadFromMem(0x1b, k);
  	printf("The value read of the DLP is:0x%d\n", valor2[k]);

  }
  return 0;
}
