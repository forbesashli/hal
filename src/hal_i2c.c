#include "hal_i2c.h"


hal_error_E i2c_init(hal_i2c_handle_S *I2C_Handle, I2C_HandleTypeDef *hi2c, I2C_TypeDef *I2C, uint32_t Timing) {
    I2C_Handle->I2C = I2C;
    I2C_Handle->hi2c = hi2c;
    I2C_Handle->Timing = 0x60404E72;
  
    if (HAL_I2C_Init(I2C_Handle->hi2c) != HAL_ERROR_OK) {
        return HAL_ERROR_ERR;
    }
    return HAL_ERROR_OK;
}


hal_error_E i2c_master_send_data(hal_i2c_handle_S *I2C_Handle, uint8_t data) {
    // You may want to add a register address as argument
    if (HAL_I2C_Master_Transmit(I2C_Handle->hi2c, I2C_Handle->hi2c->Init.OwnAddress1, &data, 1, 100) != HAL_ERROR_OK) {
        return HAL_ERROR_ERR;
    }
    return HAL_ERROR_OK;
}

hal_error_E i2c_read_data(hal_i2c_handle_S *I2C_Handle) {
    uint8_t data;
    if (HAL_I2C_Master_Receive(I2C_Handle->hi2c, I2C_Handle->hi2c->Init.OwnAddress1, &data, 1, 100) != HAL_ERROR_OK) {
        return HAL_ERROR_ERR;
    }
    // You may want to return the data or store it in the handle
    return HAL_ERROR_OK;
}