#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include <stdlib.h>

#include "token.h"

typedef struct {
  FILE* file;
  int line;
  int col;
} FileScanner;

FileScanner NewFileScanner(const char* filePath);
void FileScanner_Close(FileScanner *scanner);
Token FileScanner_GetNextToken(FileScanner* scanner);

#endif