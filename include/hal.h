#ifndef HAL_H
#define HAL_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  HAL_ERROR_OK,
  HAL_ERROR_ERR,
  HAL_ERROR_UNKNOWN,
} hal_error_E;

// Contains all chip init code.
hal_error_E hal_init(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* HAL_H */
