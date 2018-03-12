#include "i2c.h"

// I2C bus constructor
I2cBus::I2cBus(int bus_n){
  /* Access an I2C bus adapter from a C++ program */

  char file_name[15]; // To hold /dev/i2c-#
  snprintf(file_name, sizeof(file_name), "/dev/i2c-%d", bus_n);

  /* Open I2C bus driver */
  if ((file_ = open(file_name, O_RDWR)) < 0) {
    /* ERROR HANDLING: you can check errno to see what went wrong */
    perror("Failed to open the I2C bus.\n");
    exit(1);
  }
}

void I2cBus::Scan() {
  avail_addr = 0b1010011;  // 0x53
}

// void I2cBus::WriteToMem(uint8_t addr, uint8_t mem_addr){
//   uint8_t w_buf[2];
//
//   // Write to defined register
//   w_buf[0] = addr;
//
// }
