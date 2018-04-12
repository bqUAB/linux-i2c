// I2C demo using a Terasic DE10 nano board which includes an ARM processor and
// a Digital Accelerometer available at the I2C 0 bus. The board is running a
// custom Linux distro that can be obtained from Terasic's web site.

#include <stdio.h>
#include "i2c.h"


int main() {
  I2cBus i2c_0(0);

  // Digital Accelerometer
  int address = 0x53;
  int devid = 0;

  int value = i2c_0.ReadFromMem(address, devid);
  printf("The devid should be: 0xE5\n");
  printf("The HEX value read is: %#X\n", value);

  if (value == 0xE5) {
    printf("Test Passed\n" );
  } else {
    printf("Test not Passed\n");
  }

  return 0;
}
