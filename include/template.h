/**
 * @file template.h
 * @brief Provides functions for parsing and processing input strings.
 */

#ifndef TEMPLATE_H
#define TEMPLATE_H
#include "status_codes.h"

/**
 * @brief Parses command-line arguments for an input string.
 *
 * @param[in] argc Number of command-line arguments.
 * @param[in] argv Array of command-line argument strings.
 * @param[out] input_string Receives the parsed input string.
 * @return SUCCESS if the input is parsed successfully,
 *         WARNING_EMPTY_STRING if the input string is empty,
 *         ERROR_NO_INPUT if no input is provided, or
 *         ERROR_INVALID_ARGUMENT if an unsupported argument is provided.
 */
status_code_t parse_input(int argc, char *argv[], char **input_string);

/**
 * @brief Processes the given input string and prints it to stdout.
 *
 * @param[in] input_string The input string to process.
 * @return SUCCESS if the input is processed successfully,
 *         WARNING_EMPTY_STRING if the input string is empty, or
 *         ERROR_NULL_STRING if input_string is NULL.
 */
status_code_t template(char *input_string);

#endif /* TEMPLATE_H */
