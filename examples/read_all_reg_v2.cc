#include <stdio.h>
#include "../i2c.h"

int main() {
  I2cBus i2c_2(2);

  int mpu_values[128] = {0};  // MPU register values
  int dlp_values[256] = {0};  // DLP register values

  for (int j=0; j<256 ; j++) {
    if (j<128) {
      mpu_values[j]= i2c_2.ReadFromMem(0x68, j);
      printf("The value read of the MPU register %#X is: %#X\n", j,
             mpu_values[j]);
    }
    dlp_values[j]= i2c_2.ReadFromMem(0x1b, j);
    printf("The value read of the DLP register %#X is: %#X\n", j,
           dlp_values[j]);
  }
  return 0;
}
