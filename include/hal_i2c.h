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

#ifdef __cplusplus
extern "C" {
#endif
    hal_error_E i2c_init(I2C_TypeDef *I2C);
    hal_error_E i2c_send_addr(I2C_TypeDef *I2C, uint8_t addr);
    hal_error_E i2c_send_data(I2C_TypeDef *I2C, uint8_t data);
    hal_error_E i2c_read_data(I2C_TypeDef *I2C);

#ifdef __cplusplus
}
#endif /* __cplusplus */   

#endif /* HAL_I2C_H */