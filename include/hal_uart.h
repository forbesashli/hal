#ifndef HAL_UART_H
#define HAL_UART_H

#include "hal.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  // NOTE: More can be added to this interface to support DMA streaming or asynchronous transfers
  hal_error_E (*initChannel)(void);
  hal_error_E (*sendByte)(uint8_t data);
} hal_uart_channelConfig_S;

typedef struct {
  // constant address and constant data please
  hal_uart_channelConfig_S const * const channels;
  const uint8_t channelCount;
} hal_uart_config_S;

hal_error_E hal_uart_init(hal_uart_config_S const * const config);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* HAL_UART_H */
