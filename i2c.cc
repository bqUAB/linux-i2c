#include "i2c.h"

void I2cBus::WriteToMem(uint8_t addr, uint8_t mem_addr){
  uint8_t w_buf[2];

  // Write to defined register
  w_buf[0] = addr;

}
