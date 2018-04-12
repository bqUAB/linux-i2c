// I2C example to read all MPU9250 registers, the MPU is available at the
// I2C 1 bus. The program is tested on ARM Linux.

#include <stdio.h>
#include "../i2c.h"

int main() {
  I2cBus i2c_1(1);

  int addr = 0x68;  // MPU9250 address
  int values[128] = {0};  // MPU register values, not all of them are used

  for (int i = 0; i < 128; i++) {
    values[i] = i2c_1.ReadFromMem(addr, i);
    printf("The value read of the MPU 9250 register %#X ", i);
    printf("is: %#X\n", values[i]);
  }

  return 0;
}
