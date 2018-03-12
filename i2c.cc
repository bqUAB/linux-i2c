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
  /*Scan all I2C addresses between 0x08 and 0x77 inclusive and return a list
  of those that respond. A device responds if it pulls the SDA line low after
  its address (including a write bit) is sent on the bus.*/

  avail_addr = 0b1010011;  // 0x53
}

void I2cBus::WriteToMem(uint8_t addr, uint8_t mem_addr, uint8_t buff){
  /* Write buf to the slave specified by addr starting from the memory address
  specified by mem_addr.*/

  if (ioctl(file_, I2C_SLAVE, addr) < 0) {
        printf("Failed to acquire bus access and/or talk to slave.\n");
        /* ERROR HANDLING; you can check errno to see what went wrong */
        exit(1);
    }

  //uint8_t bSuccess = 0;
  uint8_t w_buf[2];

  /* Write to define register */
  w_buf[0] = mem_addr;
  w_buf[1] = buff;
  if (write(file_, &w_buf, sizeof(w_buf)) == sizeof(w_buf)){
    //bSuccess = 1;
  } else {
    /* ERROR HANDLING: i2c transaction failed */
    //bSuccess = 0;
  }
}
