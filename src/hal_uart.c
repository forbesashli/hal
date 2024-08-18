#include <string.h>

#include "hal_uart.h"
#include "hal.h"

// Contains global state for hal_uart
typedef struct {
  hal_uart_config_S const * config;
} hal_uart_data_S;

static hal_uart_data_S hal_uart_data;
static hal_uart_data_S * const data = &hal_uart_data;

hal_error_E hal_uart_init(hal_uart_config_S const *const config) {
  // zero out the data struct
  memset(data, 0U, sizeof(hal_uart_data_S));
  hal_error_E ret = HAL_ERROR_OK;
  // If the config is not NULL, assuming all other sub pointers have also been
  // assigned properly
  if (config != NULL) {
      data->config = config;
      for (uint8_t i = 0; i < config->channelCount; i++) {
          const hal_uart_channelConfig_S *const channel = &config->channels[i];
          hal_error_E channelInitError = channel->initChannel();

          if (channelInitError != HAL_ERROR_OK) {
              ret = HAL_ERROR_ERR;
          }
      }
  } else {
      // return an error if the config is NULL
      ret = HAL_ERROR_ERR;
  }

  return ret;
}

hal_error_E hal_uart_sendByte(hal_uart_channel_E channel, uint8_t byte) {
  return data->config->channels[channel].sendByte(byte);
}

hal_error_E hal_uart_sendChar(hal_uart_channel_E channel, char c) {
  return data->config->channels[channel].sendByte((uint8_t)c);
}

// String and byte array functions
hal_error_E hal_uart_sendString(hal_uart_channel_E channel, char *string) {
  return HAL_ERROR_OK;
}

hal_error_E hal_uart_sendByteArray(hal_uart_channel_E channel, uint8_t *bytes) {
  return HAL_ERROR_OK;
}
