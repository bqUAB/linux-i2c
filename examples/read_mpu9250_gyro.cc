// I2C example to read all MPU9250 gyro registers, the MPU is available at the
// I2C 1 bus. The program is tested on ARM Linux.

#include <stdio.h>
#include "i2c.h"


int main() {
  I2cBus i2c_1(1);

  uint16_t addr = 0x68;  // MPU9250 address
  uint8_t gyro_xout_h = 0x43;  // starting MPU register address from which to read
  uint8_t gyro[6] = {0};
  uint16_t gyro_x = 0;
  uint16_t gyro_y = 0;
  uint16_t gyro_z = 0;

  // Read 6 register values starting from gyro_xout_h
  i2c_1.ReadFromMemInto(addr, gyro_xout_h, 6, gyro);
  for (int i = 0; i < 6; i++) {
    printf("gyro[%d] = %#X\n", i, gyro[i]);
  }

  gyro_x |= gyro[0] << 8;
  // printf("Gyro x: %#X\n", gyro_x);
  gyro_x |= gyro[1];
  printf("Gyro x: %#X\n", gyro_x);

  gyro_y |= gyro[2] << 8;
  // printf("Gyro y: %#X\n", gyro_y);
  gyro_y |= gyro[3];
  printf("Gyro y: %#X\n", gyro_y);

  gyro_z |= gyro[4] << 8;
  // printf("Gyro y: %#X\n", gyro_z);
  gyro_z |= gyro[5];
  printf("Gyro y: %#X\n", gyro_z);

  return 0;
}
