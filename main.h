#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

void runFile(const char *file_path);
void runPrompt();
void run(const char *command);
void error(int line, const char *message);
void report(int line, const char *where, const char *message);