// I2C demo using a Terasic DE10 nano board which includes an ARM processor
// and a Digital Accelerometer available at the I2C 0 bus. The board is
// running a custom Linux distro that can be obtained from Terasic's web site.

#include <stdio.h>
#include <cstdint>  // Needed for uint8_t
#include "i2c.h"


int main() {
  I2cBus i2c_bus(0);

  // Digital Accelerometer
  uint16_t address = 0x53;
  uint8_t devid = 0;
  uint8_t value = 0;

  i2c_bus.ReadFromMem(address, devid, &value);
  printf("The devid should be: 0xE5\n");
  printf("The HEX value read is: %#X\n", value);

  if (value == 0xE5) {
    printf("Test Passed\n" );
  } else {
    printf("Test not Passed\n");
  }

  return 0;
}
