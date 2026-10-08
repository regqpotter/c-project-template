/**
 * @file template.c
 * @brief Implementation of the template function.
 */

#include "template.h"
#include "logging.h"
#include "status_codes.h"
#include <stdio.h>

status_code_t template(char *input_string) {

    log_info("Processing input string...");
    if (input_string == NULL) {
        log_error(status_code_string(ERROR_NULL_STRING));
        return ERROR_NULL_STRING;
    } else if (*input_string == '\0') {
        log_warning(status_code_string(WARNING_EMPTY_STRING));
        return WARNING_EMPTY_STRING;
    }

    else {
        log_info(input_string);
    }

    return SUCCESS;
}
