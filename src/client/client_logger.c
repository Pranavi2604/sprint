#include "../include/client_utils.h"

// Function to initialize the logger
void logger_init() {
    t = time(NULL);
    struct tm *tm = localtime(&t);
    char log_filename[200];

    // Set the absolute log file path
    sprintf(log_filename, "/home2/user19/mpcc/log/client_log/%d-%02d-%02d.log", 
            tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);
    
    // Open the log file
    log_file = fopen(log_filename, "a+");
    if (log_file == NULL) {
        perror("Error opening log file");
        exit(EXIT_FAILURE);  // Exit if the log file cannot be opened
    }
}

// Function to log messages
void logger(char *level, char *filename, int line_number, char *message, char *activity, char *event) {
    // Ensure log_file is initialized before logging
    if (log_file == NULL) {
        fprintf(stderr, "Log file is not initialized. Cannot log message.\n");
        return;  // Return if log_file is not available
    }

    // Get the current time for the log entry
    char* timeString = asctime(localtime(&t));
    timeString[strcspn(timeString, "\n")] = '\0';  // Remove newline character

    // Log the message
    fprintf(log_file, "{\"asctime\": \"%s\", \"level\": \"%s\", \"file\": \"%s\", \"line\": \"%d\", \"message\": \"%s\", \"activity\": \"%s\", \"event\": \"%s\"}\n",
            timeString, level, filename, line_number, message, activity, event);
    
    fflush(log_file);  // Ensure the log is written to the file immediately
}

// Function to close the log file
void logger_close() {
    if (log_file != NULL) {
        fclose(log_file);
        log_file = NULL;  // Set to NULL after closing
    }
}

