/**
 * @file logging.h
 * @brief Logging utility functions for the project.
 */

#ifndef LOGGING_H
#define LOGGING_H

/**
 * @brief A message passed to the logger is displayed on the standard output
 *        console and, when file logging is enabled, also written to the
 *        log file.
 * @param message The message to log.
 */
void log_info(const char *message);

/**
 * @brief A warning message passed to the logger is displayed on the standard
 *        error console and, when file logging is enabled, also written to the
 *        log file.
 * @param message The warning message to log.
 */
void log_warning(const char *message);

/**
 * @brief An error message passed to the logger is displayed on the standard
 *        error console and, when file logging is enabled, also written to the
 *        log file.
 * @param message The error message to log.
 */
void log_error(const char *message);

/**
 * @brief Initializes the logging system.
 * @note If file logging is enabled, the log file is created in the
 *       build directory.
 */
void start_logging(void);

/**
 * @brief Shuts down the logging system.
 */
void end_logging(void);
#endif /* LOGGING_H */