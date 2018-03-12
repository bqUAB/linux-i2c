/* Simplified I2C class based on:
http://docs.micropython.org/en/latest/wipy/library/machine.I2C.html
*/
#ifndef I2C_H
#define I2C_H

#include <stdio.h>          // Needed for printf, snprintf, perror
#include <cstdint>  // Needed for unit uint8_t data type
#include <fcntl.h>          // Needed for open()
// #include <unistd.h>         // Needed for close()
#include <stdlib.h>         // Needed for exit()
// #include <sys/ioctl.h>      // Needed for ioctl
// #include <linux/i2c-dev.h>  // Needed to use the I2C Linux driver (I2C_SLAVE)

class I2cBus {
  private:
    int file_ = 0;
    int list_[5];

  public:
    uint8_t avail_addr;

  I2cBus(int bus_n);

  /* --------------------------- General Methods --------------------------- */
    void Scan();
  /*Scan all I2C addresses between 0x08 and 0x77 inclusive and return a list
  of those that respond. A device responds if it pulls the SDA line low after
  its address (including a write bit) is sent on the bus.*/
  /* -------------------------- Memory Operations --------------------------
  Some I2C devices act as a memory device (or set of registers) that can be
  read from and written to. In this case there are two addresses associated
  with an I2C transaction: the slave address and the memory address. The
  following methods are convenience functions to communicate with such
  devices.*/

    int ReadFromMem(uint8_t addr, uint8_t mem_addr, int n_bytes);
  /* Read nbytes from the slave specified by addr starting from the memory
  address specified by memaddr. The argument addrsize specifies the address
  size in bits. Returns a bytes object with the data read.*/

    void ReadFromMemInto(uint8_t addr, uint8_t memaddr, int* buff);
  /* Read into buf from the slave specified by addr starting from the memory
  address specified by memaddr. The number of bytes read is the length of buf.
  The argument addrsize specifies the address size in bits (on ESP8266 this
  argument is not recognised and the address size is always 8 bits).*/

    void WriteToMem(uint8_t addr, uint8_t memaddr, int* buff);
  /* Write buf to the slave specified by addr starting from the memory address
  specified by memaddr. The argument addrsize specifies the address size in
  bits (on ESP8266 this argument is not recognised and the address size is
  always 8 bits).*/
};

#endif // I2C_H
