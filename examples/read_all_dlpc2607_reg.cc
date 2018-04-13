// I2C example to read all DLPC2607 registers, the DLP is available at the
// I2C 1 bus. The program is tested on ARM Linux.

#include <stdio.h>
#include "../i2c.h"


int main() {
  I2cBus i2c_1(1);
  int addr = 0x1B;  // DLPC2607 address
  uint8_t value_out[4] = {0};
  int reg[256] = {0};  // DLP 32-bit register values

  for (int i = 0; i < 256; i++){
    // Read Command
    i2c_1.WriteToMem(addr, 0x15, 1, &i);  // Part 1
    i2c_1.ReadFromInto(addr, value_out);  // Part 2
    for (int j = 0; j < 4; j++) {
      reg[i] |= value_out[j] << 8*(3 - j);
    }

    printf("reg[%#X] = %#X\n", i, reg[i]);
  }

  return 0;
}
