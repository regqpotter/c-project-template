/**
 * @file status_codes.c
 * @brief Implementation of status code string conversion.
 */

#include "status_codes.h"

const char *status_code_string(status_code_t status) {
    switch (status) {
    case SUCCESS:
        return "Success";

    case WARNING_EMPTY_STRING:
        return "Empty string";

    case ERROR_NULL_STRING:
        return "NULL string";

    case ERROR_NO_INPUT:
        return "No input given";

    case ERROR_INVALID_ARGUMENT:
        return "Invalid argument";

    default:
        return "Unknown status";
    }
}