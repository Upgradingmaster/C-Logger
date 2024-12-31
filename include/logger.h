#ifndef LOGGING
#define LOGGING
int LoggerOpen();
void Logc(char c);
void Logs(char* message);
void Logf(char* format, ...);
void LoggerClose();
#endif
