#include "i2c.h"


// I2C bus constructor
I2cBus::I2cBus(int bus_n) {
  // Access an I2C bus adapter from a C++ program

  char file_name[15]; // To hold /dev/i2c-#
  snprintf(file_name, sizeof(file_name), "/dev/i2c-%d", bus_n);

  // Open I2C bus driver
  if ((file_ = open(file_name, O_RDWR)) < 0) {
    // ERROR HANDLING: you can check errno to see what went wrong
    perror("Failed to open the I2C bus.\n");
    exit(1);
  }
}

int I2cBus::SetSlaveAddr_(int addr) {
  int success;
  // Input output control setup to the slave device.
  if (ioctl(file_, I2C_SLAVE, addr) < 0) {
    success = 0;
    perror("Failed to acquire bus access and/or talk to slave.\n");
    // ERROR HANDLING; you can check errno to see what went wrong
    exit(1);
  } else {
    success = 1;
  }

  return success;
}

int I2cBus::ReadFromInto(int addr, uint8_t* buff) {
  // Read into buf from the slave specified by addr. The number of bytes read
  // will be the length of buff

  int success;

  SetSlaveAddr_(addr);
  if (read(file_, buff, sizeof(buff)) == sizeof(buff)) {
    success = 1;
  } else {
    success = 0;
    perror("I2C read from slave into buffer failed.\n");
    // ERROR HANDLING; you can check errno to see what went wrong
  }

  return success;
}

int I2cBus::WriteToMem(int addr, int mem_addr, int n_bytes, int* buff) {
  // Write buff to the slave specified by addr starting from the memory
  // address specified by mem_addr.

  int success;
  uint8_t w_buff[1 + n_bytes];  // cannot create type information for type
                                // 'int [(n_bytes + 1)]' because it involves
                                // types of variable size

  SetSlaveAddr_(addr);
  w_buff[0] = mem_addr;
  // Shift and then fill the buffer
  for (int i = 1; i <= n_bytes; i++) {
    w_buff[i] = buff[i-1];
  }

  // Write to define register
  if (write(file_, &w_buff, sizeof(w_buff)) == int(sizeof(w_buff))) {
                                            // ^ int casting due to
                                            // uint comparison warning
    success = 1;
  } else {
    // ERROR HANDLING: i2c transaction failed
    success = 0;
  }

  return success;
}

int I2cBus::ReadFromMem(int addr, int mem_addr) {
  // Read a byte from the slave specified by addr starting from the memory
  // address specified by mem_addr.

  int data = 0; // 'data' will store the register data

  SetSlaveAddr_(addr);

  // Write to defined register
  if (write(file_, &mem_addr, 1) == 1) {
    // Read back value
    if (read(file_, &data, 1) != 1) {
      perror("I2C read failed.\n");
      // ERROR HANDLING; you can check errno to see what went wrong
      exit(1);
    }
  }

  return data;
}

int I2cBus::ReadFromMemInto(int addr, int mem_addr, int n_bytes,
                             uint8_t* buff)
{
  // Read n_bytes into buff from the slave specified by addr starting from
  // the memory address specified by mem_addr.

  int success;

  SetSlaveAddr_(addr);
  // Write to defined register
  if (write(file_, &mem_addr, 1) == 1) {
    // read back value
    if (read(file_, buff, n_bytes) == n_bytes) {
      success = 1;
    } else {
      success = 0;
      perror("I2C read from memory into buffer failed.\n");
    }
  }

  return success;
}
