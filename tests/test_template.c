/**
 * @file test_template.c
 * @brief Unit tests for the template function.
 */

#include "logging.h"
#include "status_codes.h"

#include "template.h"
#include <assert.h>
#include <stdio.h>

/**
 * @brief Tests the template function with valid input.
 */
static void test_valid_input(void) { assert(template("Sample String") == SUCCESS); }

/**
 * @brief Tests the template function with an empty string.
 */
static void test_empty_input(void) { assert(template("") == WARNING_EMPTY_STRING); }

/**
 * @brief Tests the template function with a NULL input.
 */
static void test_null_input(void) { assert(template(NULL) == ERROR_NULL_STRING); }

/**
 * @brief Main function to run all tests.
 * @return 0 if all tests pass. Non-zero otherwise.
 */
int main(void) {
    log_info("Starting unit tests for template function...");
    test_valid_input();
    test_empty_input();
    test_null_input();

#ifdef REGRESSION
    /* Add regression-only tests here and modify Makefile accordingly. */
#endif

    log_info("All tests passed.");
    return 0;
}