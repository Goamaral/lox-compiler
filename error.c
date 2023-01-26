#include "error.h"

bool hadError = false;
char error[1024];

void criticalError(int status, const char *where, const char *msg) {
  if (hadError) logError();
  fprintf(stderr, "Critical error @ %s -> %s", where, msg);
  if (errno != EX_OK) fprintf(stderr, ": %s", strerror(errno));

  exit(status);
}

// TODO: Support vargs
void reportError(const char *where, const char *msg) {
  if (errno != EX_OK) {
    sprintf(error, "Error @ %s -> %s: %s\n", where, msg, strerror(errno));
  } else {
    sprintf(error, "Error @ %s -> %s\n", where, msg);
  }
  memset(error, 0, 1024);
  hadError = true;
}

void logError() {
  fputs(error, stderr);
  hadError = false;
}

void reportCompilationError(int line, int col, const char *msg) {
  sprintf(error, "Compilatior error @ %d:%d -> %s\n", line, col, msg);
  hadError = true;
}