#include "token.h"

Token NewToken(TokenType type, char *lexeme, char *literal, int line) {
  Token tok = {type, lexeme, literal, line};
  return tok;
}

int TokenToString(Token tok, char *dst) {
  return sprintf(dst, "%s %s %s", tok.type, tok.lexeme, tok.literal);
}