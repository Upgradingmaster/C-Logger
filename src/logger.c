#include "logger.h"
#include <stdarg.h>
#include <stdio.h>

#define A_LOGFILE "./logs/a_log"
FILE* a_file = NULL;

#define W_LOGFILE "./logs/o_log" 
FILE* o_file = NULL;

// Return -1 on fail
int LoggerOpen() {
    int tries = 3;
    while ((a_file == NULL || o_file == NULL) && tries != 0) {
        a_file = fopen(A_LOGFILE, "a");
        o_file = fopen(W_LOGFILE, "w");
        tries--;
    }
    if (tries == 0){
        return -1;
    }
    return 0;
}

void Logc(char c) {
    putc(c, a_file);
    putc(c, o_file);
}

void Logs(char* message) {
    fprintf(a_file, "%s\n", message);
    fprintf(o_file, "%s\n", message);
}

void Logf(char* format, ...) {
    va_list args;
    va_start(args, format);
    char message[100];
    vsnprintf(message, 100, format, args);
    va_end(args);

    fprintf(a_file, "%s\n", message);
    fprintf(o_file, "%s\n", message);
}


void LoggerClose() {
    if (a_file != NULL){
        fflush(a_file); fclose(a_file);
    }
    if (o_file != NULL){
        fflush(o_file); fclose(o_file);
    }
};
