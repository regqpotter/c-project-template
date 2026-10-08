/**
 * @file logging.c
 * @brief Implements logging utility functions for the project.
 */

#include "logging.h"
#include <stdio.h>
#include <time.h>

/* Break the compile if the user forgot to add a LOG_FILE_PATH */
#if defined(LOG_TO_FILE) && !defined(LOG_FILE_PATH)
#error "LOG_FILE_PATH must be defined when LOG_TO_FILE is enabled."
#endif

#define TIMESTAMP_SIZE 20

/**
 * @brief Log levels for different types of messages.
 */
typedef enum { LOG_LEVEL_INFO = 0, LOG_LEVEL_WARNING, LOG_LEVEL_ERROR } log_level_t;

/**
 * @brief Logs a message with a specified information type (INFO, WARNING, ERROR).
 * @param log_level The log level indicating the type of message.
 * @param message The message to log.
 */
static void log_message(log_level_t log_level, const char *message);

/**
 * @brief Retrieves the current timestamp as a string.
 * @param buffer A character array to store the timestamp string.
 * @param buffer_size The size of the buffer.
 */
static void get_current_timestamp(char *buffer, size_t buffer_size);

void start_logging(void) {
#ifdef LOG_TO_FILE
    FILE *log_file = fopen(LOG_FILE_PATH, "w");
    if (log_file != NULL) {
        (void)fclose(log_file);
    } else {
        (void)fprintf(stderr, "[ERROR] Failed to open log file at start: %s\n", LOG_FILE_PATH);
    }
#endif /* LOG_TO_FILE */
    log_info("[START LOGGING]");
}

void log_info(const char *message) { log_message(LOG_LEVEL_INFO, message); }

void log_warning(const char *message) { log_message(LOG_LEVEL_WARNING, message); }

void log_error(const char *message) { log_message(LOG_LEVEL_ERROR, message); }

void end_logging(void) { log_info("[END LOGGING]"); }

static void get_current_timestamp(char *buffer, size_t buffer_size) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    (void)strftime(buffer, buffer_size, "%Y-%m-%d %H:%M:%S", tm_info);
}

static void log_message(log_level_t log_level, const char *message) {
    char timestamp[TIMESTAMP_SIZE];
    get_current_timestamp(timestamp, TIMESTAMP_SIZE);
    const char *level_string;
    switch (log_level) {
    case LOG_LEVEL_INFO:
        level_string = "[INFO]";
        break;
    case LOG_LEVEL_WARNING:
        level_string = "[WARNING]";
        break;
    case LOG_LEVEL_ERROR:
        level_string = "[ERROR]";
        break;
    default:
        level_string = "[UNKNOWN]";
        break;
    }
#ifdef LOG_TO_FILE
    FILE *log_file = fopen(LOG_FILE_PATH, "a");
    if (log_file != NULL) {
        (void)fprintf(log_file, "%s %s:\n\t%s\n", level_string, timestamp, message);
        (void)fclose(log_file);
    } else {
        (void)fprintf(stderr, "[ERROR] Failed to open log file: %s\n", LOG_FILE_PATH);
    }
#endif /* LOG_TO_FILE */
#ifdef LOG_TO_CONSOLE
    if (log_level == LOG_LEVEL_INFO) {
        (void)printf("%s %s:\n\t%s\n", level_string, timestamp, message);
    } else {
        (void)fprintf(stderr, "%s %s:\n\t%s\n", level_string, timestamp, message);
    }
#endif /* LOG_TO_CONSOLE */
}
