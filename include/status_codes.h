/**
 * @file status_codes.h
 * @brief Defines status codes and related macros for error handling.
 */

#ifndef STATUS_CODES_H
#define STATUS_CODES_H

#include <stdint.h>

/**
 * @brief Type representing a status code.
 */
typedef uint32_t status_code_t;

/**
 * @brief Masks used to determine the severity of a status code.
 */
#define STATUS_SEVERITY_MASK 0xC0000000U
#define STATUS_WARNING_MASK 0x40000000U
#define STATUS_ERROR_MASK 0x80000000U

/**
 * @brief Macro to check if a status code indicates success.
 */
#define STATUS_IS_SUCCESS(status) (((status) & STATUS_SEVERITY_MASK) == 0U)

/**
 * @brief Macro to check if a status code indicates a warning.
 */
#define STATUS_IS_WARNING(status) (((status) & STATUS_SEVERITY_MASK) == STATUS_WARNING_MASK)

/**
 * @brief Macro to check if a status code indicates an error.
 */
#define STATUS_IS_ERROR(status) (((status) & STATUS_SEVERITY_MASK) == STATUS_ERROR_MASK)

/**
 * @brief Enumeration of status codes.
 * @note The 2 most significant bits of the status code indicate the severity
 *          (success, warning, error, reserved).
 */

/** Operation completed successfully. */
#define SUCCESS 0x00000000U

/** Input string is empty. */
#define WARNING_EMPTY_STRING 0x40000001U

/** Input string pointer is NULL. */
#define ERROR_NULL_STRING 0x80000001U

/** Required input was not provided. */
#define ERROR_NO_INPUT 0x80000002U

/** An unsupported command-line argument was provided. */
#define ERROR_INVALID_ARGUMENT 0x80000003U

/**
 * @brief Converts a status code to its string representation.
 *
 * @param[in] status The status code to convert.
 * @return A pointer to a string representing the status code.
 */
const char *status_code_string(status_code_t status);

#endif /* STATUS_CODES_H */