#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>

typedef enum {
  TokenType_UNDEFINED,

  // Single-character tokens.
  TokenType_LPAR,
  TokenType_RPAR,
  TokenType_LBRACE,
  TokenType_RBRACE,
  TokenType_COMMA,
  TokenType_DOT,
  TokenType_MINUS,
  TokenType_PLUS,
  TokenType_SEMICOLON,
  TokenType_SLASH,
  TokenType_STAR,

  // One or two character tokens.
  TokenType_BANG,
  TokenType_BANG_EQUAL,
  TokenType_EQ,
  TokenType_EQ_EQ,
  TokenType_GT,
  TokenType_GTE,
  TokenType_LT,
  TokenType_LTE,

  // Literals.
  TokenType_ID,
  TokenType_STRING,
  TokenType_NUMBER,

  // Keywords.
  TokenType_AND,
  TokenType_CLASS,
  TokenType_ELSE,
  TokenType_FALSE,
  TokenType_FUNC,
  TokenType_FOR,
  TokenType_IF,
  TokenType_NIL,
  TokenType_OR,
  TokenType_PRINT,
  TokenType_RETURN,
  TokenType_SUPER,
  TokenType_THIS,
  TokenType_TRUE,
  TokenType_VAR,
  TokenType_WHILE,

  TokenType_EOF
} TokenType;

typedef struct {
  TokenType type;
  char* lexeme;
  char* literal;
  int line;
  int col;
} Token;

Token NewToken(TokenType type, char *lexeme, char *literal, int line);
int Token_ToString(Token tok, char *dst);

#endif
