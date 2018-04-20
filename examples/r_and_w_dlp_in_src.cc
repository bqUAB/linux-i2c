// I2C example to write and read the DLPC2607 input source selection register.
// The DLP is available at the I2C 1 bus. The program is tested on ARM Linux.

#include <stdio.h>
#include <cstdint>  // Needed for uint8_t
#include "../i2c.h"


int main() {
  I2cBus i2c_bus(1);

  uint16_t addr = 0x1B;  // DLPC2607 address
  uint8_t reg = 0x0B;  // Input source selection
  uint8_t value_in[4] = {0, 0, 0, 1};  // Internal test pattern
  uint8_t value_out[4] = {0};
  int value = 0;  // 32-bit value

  // Write Command
  i2c_bus.WriteToMemFrom(addr, reg, 4, value_in);

  // Read Command
  i2c_bus.WriteToMem(addr, 0x15, reg);  // Part 1
  i2c_bus.ReadFromInto(addr, value_out);  // Part 2

  for (int i = 0; i < int(sizeof(value_out)); i++) {
    value |= value_out[i] << 8*(3 - i);
    printf("value_out[%d] = %#X\n", i, value_out[i]);
  }

  printf("Value = %#X\n", value);

  return 0;
}
