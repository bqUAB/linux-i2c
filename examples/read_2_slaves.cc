#include <stdio.h>
#include "../i2c.h"

int main() {
  I2cBus i2c_bus(2);
  int mpu_value = i2c_bus.ReadFromMem(0x68, 0x75);  // MPU 9250
  int dlp_value = i2c_bus.ReadFromMem(0x1b, 0x03);  // DLP 2000 EVM
  printf("The value read is: %#X for the MPU and %#X for the DLP\n",
         mpu_value, dlp_value);
  return 0;
}
