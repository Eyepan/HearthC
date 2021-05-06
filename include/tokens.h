#include <stdio.h>
#ifndef TOKEN_H
#define TOKEN_H
#include <string.h>

#define TT_INT 			"INT"
#define TT_FLOAT		"FLOAT"

#define TT_PLUS			"PLUS"
#define TT_MINUS		"MINUS"
#define TT_MUL			"MUL"
#define TT_DIV			"DIV"
#define TT_EXP			"EXP"
#define TT_MOD			"MOD"

#define TT_LPAREN		"LPAREN"
#define TT_RPAREN		"RPAREN"

#define TT_EOF			"EOF"

typedef struct TOKEN_STRUCT
{
	char* type;
	char* value;
} token_T;

token_T* initToken(char* type, char* value);
void printToken(token_T* token);

#endif