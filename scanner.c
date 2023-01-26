#include "scanner.h"

#include "error.h"
#include "token.h"

FileScanner NewFileScanner(const char* filePath) {
  FileScanner scanner = {.line = 1, .col = 1};

  FILE* file = fopen(filePath, "r");
  if (file == NULL) {
    reportError("NewFileScanner", "Failed to open file");
    return scanner;
  }

  scanner.file = file;
  return scanner;
}

void FileScanner_Close(FileScanner* scanner) { fclose(scanner->file); }

Token FileScanner_GetNextToken(FileScanner* scanner) {
  Token tk;
  long tokenStart = ftell(scanner->file);
  long tokenLength = 1; // \0

  char c = fgetc(scanner->file);
  if (feof(scanner->file)) {
    tk.type = TokenType_EOF;
    return tk;
  }
  if (c == '\n') {
    scanner->line++;
    scanner->col = 1;
  }
  tokenLength++;

  switch (c) {
    case '(':
      tk.type = TokenType_LPAR;
      break;
    case ')':
      tk.type = TokenType_RPAR;
      break;
    case '{':
      tk.type = TokenType_LPAR;
      break;
    case '}':
      tk.type = TokenType_RPAR;
      break;
    case ',':
      tk.type = TokenType_COMMA;
      break;
    case '.':
      tk.type = TokenType_DOT;
      break;
    case '-':
      tk.type = TokenType_MINUS;
      break;
    case '+':
      tk.type = TokenType_PLUS;
      break;
    case ';':
      tk.type = TokenType_SEMICOLON;
      break;
    case '*':
      tk.type = TokenType_STAR;
      break;

    default:
      reportCompilationError(scanner->line, scanner->col, "Unexpected character");
      break;
  }

  tk.line = scanner->line;
  tk.col = scanner->col;
  tk.lexeme = (char*)malloc(sizeof(char) * tokenLength);
  fseek(scanner->file, tokenStart, SEEK_SET);
  fgets(tk.lexeme, tokenLength, scanner->file);

  return tk;
}