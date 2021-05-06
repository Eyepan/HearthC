#include <tokens.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>	

token_T* initToken(char* type, char* value)
{
	token_T *tok = calloc(1, sizeof(struct TOKEN_STRUCT));
	tok->type = type;
	tok->value = value;
	return tok;
}
void printToken(token_T* token)
{
	if (!strcmp(token->type, TT_INT) || !strcmp(token->type, TT_FLOAT))
		printf("%s:%s ", token->type, token->value);
	else
		printf("%s ", token->type);
}