#include <stdio.h>
#include "../i2c.h"

int main() {
  I2cBus i2c_2(2);
  uint8_t mpu_value = i2c_2.ReadFromMem(0x68, 0x75);  // MPU 9250
  uint8_t dlp_value = i2c_2.ReadFromMem(0x1b, 0x03);  // DLP 2000 EVM
  printf("The value read is: %#X for the MPU and %#X for the DLP\n",
         mpu_value, dlp_value);
  return 0;
}
