#include <stdio.h>
#include "../i2c.h"

int main() {
  I2cBus i2c_2(2);

  int mpu_values[128] = {0};  // MPU register values
  int dlp_values[256] = {0};  // DLP register values

  for (int j=0; j<128; j++){
    mpu_values[j]= i2c_2.ReadFromMem(0x68, j);
    printf("The value read of the MPU register %#X is: %#X\n", j,
           mpu_values[j]);
  }
  printf("\n");
  for (int k=0; k<256; k++) {
    dlp_values[k]= i2c_2.ReadFromMem(0x1b, k);
    printf("The value read of the DLP register %#X is: %#X\n", k,
           dlp_values[k]);
  }
  return 0;
}
