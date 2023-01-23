#include <sysexits.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void runFile(const char *file_path);
void runPrompt();
void run(const char *command);

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

void runFile(const char *file_path) {
  FILE *file = fopen(file_path, "r");
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

    printf("%s", line);
  }

  fclose(file);
}

void runPrompt() {
  char command[1024];
  for (;;) {
    printf("> ");
    if (fgets(command, 1024, stdin) == NULL) {
      // TODO: printf("Failed to get input: %s\n", strerror(errno));
      return;
    }
    command[strlen(command)-1] = '\0'; // Remove new line

    run(command);
  }
}

void run(const char *command) {

}