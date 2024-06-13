#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include "hal.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  HAL_GPIO_PINMODE_OUTPUT_PUSH_PULL,
  HAL_GPIO_PINMODE_OUTPUT_OPEN_DRAIN,
  HAL_GPIO_PINMODE_INPUT,

  HAL_GPIO_PINMODE_UNKNOWN,
} hal_gpio_pinMode_E;

typedef enum {
  HAL_GPIO_PULLMODE_NONE,
  HAL_GPIO_PULLMODE_PULLUP,
  HAL_GPIO_PULLMODE_PULLDOWN,

  HAL_GPIO_PULLMODE_UNKNOWN,
} hal_gpio_pullMode_E;

typedef enum {
  HAL_GPIO_PINSTATE_ON,
  HAL_GPIO_PINSTATE_OFF,
  HAL_GPIO_PINSTATE_UNKNOWN,
} hal_gpio_pinState_E;

typedef struct {
  hal_error_E (*initChannel)(hal_gpio_pinMode_E initialPinMode, hal_gpio_pullMode_E initialPullMode, hal_gpio_pinState_E initialPinState);
  hal_error_E (*setOutputState)(hal_gpio_pinState_E pinState);
  hal_error_E (*setPinMode)(hal_gpio_pinMode_E pinMode);
  hal_error_E (*setPullMode)(hal_gpio_pullMode_E pullMode);
} hal_gpio_channelConfig_S;

typedef struct {
  hal_gpio_channelConfig_S const * const channels;
  const uint8_t channelCount;
} hal_gpio_config_S;

// Contains all chip init code.
hal_error_E hal_gpio_init(hal_gpio_config_S config);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* HAL_GPIO_H */
