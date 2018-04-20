// I2C example to read all MPU9250 registers, the MPU is available at the
// I2C 1 bus. The program is tested on ARM Linux.

#include <stdio.h>
#include "../i2c.h"

int main() {
  I2cBus i2c_bus(1);

  uint16_t addr = 0x68;  // MPU9250 address
  uint8_t values[128] = {0};  // MPU register values, not all of them are used
  uint8_t values_bug[128] = {0};
  uint8_t values_no_bug[11] = {0};

  printf("MPU9250 read all registers example\n");
  printf("Register Address and Value\n");

  for (uint i = 0; i < 128; i++) {
    uint8_t data = 1;
    if (i2c_bus.ReadFromMem(addr, i, &data)){
      values[i] = data;
    }
    printf("%#X = %#X\n", i, values[i]);
  }

  // Bug
  printf("Register Bug when using different methods\n");
  i2c_bus.ReadFromMemInto(addr, 0, 128, values_bug);
  for (uint i = 0; i < 128; i++) {
    printf("values[%#X] = %#X,\t", i, values[i]);
    printf("values_bug[%#X] = %#X\n", i, values_bug[i]);
  }

  i2c_bus.ReadFromMemInto(addr, 0x75, 11, values_no_bug);
  for (uint i = 0; i < 11; i++) {
    printf("values_no_bug[%#X] = %#X\n", i+0x75, values_no_bug[i]);
  }

  return 0;
}
