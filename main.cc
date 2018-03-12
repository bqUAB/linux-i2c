#include "i2c.h"
#include <iostream>
#include <stdio.h>

int main() {
  I2cBus i2c_0(0);
  i2c_0.Scan();
  printf("Available address: 0x%X\n", i2c_0.avail_addr);
  return 0;
}
