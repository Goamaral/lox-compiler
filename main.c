#include "main.h"
#include "token.h"

bool hadError = false;

int main(int argc, char *argv[]) {
  if (argc > 2) {
    printf("Usage: jlox [file]\n");
    exit(EX_USAGE);
  } else if (argc == 2) {
    runFile(argv[1]);
  } else {
    runPrompt();
  }
  return 0;
}

void runFile(const char *filePath) {
  FILE *file = fopen(filePath, "r");
  if (file == NULL) {
    printf("Failed to open file: %s\n", strerror(errno));
    return;
  }

  char line[1024];
  while (fgets(line, 1024, file) != NULL) {
    if (ferror(file)) {
      printf("Failed to read file line: %s\n", strerror(errno));
      return;
    }

    // run(command);

    if (hadError) exit(EX_DATAERR);
  }

  fclose(file);
}

void runPrompt() {
  char command[1024];
  for (;;) {
    printf("> ");
    if (fgets(command, 1024, stdin) == NULL) {
      if (errno != EX_OK) printf("Failed to get input: %s\n", strerror(errno));
      return;
    }
    command[strlen(command) - 1] = '\0';  // Remove new line

    run(command);

    hadError = false;
  }
}

void run(const char *command) {
  // TODO: Read tokens
}

void error(int line, const char *message) { report(line, "", message); }

void report(int line, const char *where, const char *message) {
  printf("[line %d] Error%s: %s", line, where, message);
  hadError = true;
}