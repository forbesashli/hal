#include <string.h>

#include "hal_gpio.h"
#include "hal_gpio_microSpecific.h"
#include "hal.h"

// Contains global state for hal_gpio
typedef struct {
  hal_gpio_config_S const * config;
} hal_gpio_data_S;

static hal_gpio_data_S hal_gpio_data;
static hal_gpio_data_S * const data = &hal_gpio_data;

hal_error_E hal_gpio_init(hal_gpio_config_S const *const config) {
  // zero out the data struct
  memset(data, 0U, sizeof(hal_gpio_data_S));
  hal_error_E ret = HAL_ERROR_OK;
  // If the config is not NULL, assuming all other sub pointers have also been
  // assigned properly
  if (config != NULL) {
      data->config = config;
      for (uint8_t i = 0; i < config->channelCount; i++) {
          const hal_gpio_channelConfig_S *const channel = &config->channels[i];
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

hal_gpio_pinState_E hal_gpio_readInputState(hal_gpio_channel_E channel) {
  return data->config->channels[channel].readPinState();
}
hal_error_E hal_gpio_setOutputState(hal_gpio_channel_E channel, hal_gpio_pinState_E pinState) {
  return data->config->channels[channel].setPinState(pinState);
}

// Should not be needed during runtime in most cases but included anyways
/* hal_error_E hal_gpio_setPinMode(hal_gpio_channel_E channel); */
/* hal_error_E hal_gpio_setPullMode(hal_gpio_channel_E channel); */
