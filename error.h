#ifndef ERROR_H
#define ERROR_H

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>

extern bool hadError;

void criticalError(int status, const char *where, const char *msg);
void reportError(const char *where, const char *msg);
void logError();
void reportCompilationError(int line, int col, const char *msg);

#endif