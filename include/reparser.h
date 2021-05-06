#ifndef PARSER_H
#define PARSER_H

#include <stacker.h>

typedef struct PARSER_STRUCT
{
	token_T tokens[512];
	stack_T stack;
} parser_T;

parser_T* initParser(token_T tokens[]);
void advance(parser_T* parser);
token_T* factor(parser_T* parser);
token_T* term(parser_T* parser);
token_T* expr(parser_T* parser);
void parse(parser_T* parser);

#endif // PARSER_H