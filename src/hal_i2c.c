#include "hal_i2c.h"


hal_error_E i2c_init(I2C_TypeDef *I2C);
hal_error_E i2c_send_addr(I2C_TypeDef *I2C, uint8_t addr);
hal_error_E i2c_send_data(I2C_TypeDef *I2C, uint8_t data);
hal_error_E i2c_read_data(I2C_TypeDef *I2C);