#include "main.h"
#include "token.h"
#include "error.h"
#include "scanner.h"

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
  FileScanner scanner = NewFileScanner(filePath);
  if (hadError) criticalError(EX_DATAERR, "runFile", "Failed initialize file scanner");

  Token tk = FileScanner_GetNextToken(&scanner);
  if (hadError) criticalError(EX_DATAERR, "runFile", "Failed to get next token");
  if (tk.type != TokenType_EOF) {
    printf("lexeme: %s line: %d col: %d type: %d", tk.lexeme, tk.line, tk.col, tk.type);
  }

  FileScanner_Close(&scanner);
}

void runPrompt() {
  // char command[1024];
  // for (;;) {
  //   printf("> ");
  //   if (fgets(command, 1024, stdin) == NULL) {
  //     if (errno != EX_OK) printf("Failed to get input: %s\n", getError());
  //     return;
  //   }
  //   command[strlen(command) - 1] = '\0';  // Remove new line

  //   run(command);

  //   hadError = false;
  // }
}

void run(const char *command) {
  // TODO
}