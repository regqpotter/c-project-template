/**
 * @file main.c
 * @brief Entry point for the program.
 */

#include "logging.h"
#include "status_codes.h"
#include "template.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// NOLINTNEXTLINE(bugprone-easily-swappable-parameters)
status_code_t parse_input(int argc, char *argv[], char **input_string) {
    log_info("Parsing command-line arguments...");
    int opt;
    status_code_t status = SUCCESS;
    while ((opt = getopt(argc, argv, "s:")) != -1) {
        switch (opt) {
        case 's':
            *input_string = optarg;
            break;
        default:
            /* Only -s options are supported.*/
            log_error("Received unsupported command-line argument.");
            status = ERROR_INVALID_ARGUMENT;
        }
    }
    if (*input_string == NULL) {
        log_error("No input string provided. Use the -s option to specify an input string.");
        return ERROR_NO_INPUT;
    } else if (**input_string == '\0') {
        log_warning("Input string is empty.");
        status = WARNING_EMPTY_STRING;
    }
    log_info("Input string parsed successfully.");
    return status;
}

/**
 * @brief Program entry point.
 *
 * @param[in] argc Number of command-line arguments.
 * @param[in] argv Array of command-line argument strings.
 * @return SUCCESS if the program completes successfully, or a status code
 *         indicating the error or warning encountered.
 */
int main(int argc, char *argv[]) {
    start_logging();
    char *input_string = NULL;
    status_code_t status = parse_input(argc, argv, &input_string);
    if (status != SUCCESS) {
        log_error(status_code_string(status));
        end_logging();
        return EXIT_FAILURE;
    }
    end_logging();
    return EXIT_SUCCESS;
}