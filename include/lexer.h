#ifndef LEXER_H
#define LEXER_H

#include "tokens.h"

typedef struct LEXER_STRUCT
{
	token_T tokens[512];
	char* text;
	int curPos;
	char curChar;
	int curTok;
} lexer_T;

lexer_T* initLexer(char* text);
void advance(lexer_T* lexer);
void makeTokens(lexer_T* lexer);
void makeNumber(lexer_T* lexer);
void printTokens(lexer_T* lexer);
token_T* getTokens(lexer_T* lexer);

#endif