/*
 * hal_i2c.h
 *
 *  Created on: July 18, 2025
 *      Author: Ashli
 * Header file for I2C HAL abstraction, lightweight version for what I have been using for beargotchi.
 */

#ifndef HAL_I2C_H
#define HAL_I2C_H

#include "hal.h"
#include <stdbool.h>
#include <stdlib.h>

// should change to a component specific header file instead
#include "stm32h7xx_hal.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    I2C_TypeDef *I2C;  // Pointer to the I2C peripheral
    I2C_HandleTypeDef *hi2c; // Handle for the I2C peripheral
    uint32_t Timing;   // Timing configuration for the I2C
} hal_i2c_handle_S;

hal_error_E i2c_init(hal_i2c_handle_S *I2C_Handle,  I2C_HandleTypeDef *hi2c, I2C_TypeDef *I2C, uint32_t Timing);
hal_error_E i2c_master_send_data(hal_i2c_handle_S *I2C_Handle, uint8_t data);
hal_error_E i2c_read_data(hal_i2c_handle_S *I2C_Handle);

#ifdef __cplusplus
}
#endif /* __cplusplus */   

#endif /* HAL_I2C_H */