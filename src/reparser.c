#include <reparser.h>
#include <string.h>
parser_T* initParser(token_T tokens[])
{
	parser_T* parser = calloc(1, sizeof(struct PARSER_STRUCT));
	for (int i = 0; !strcmp(tokens[i].type, TT_EOF); i++)
	{
		push(&parser->stack, &tokens[i]);
	}
}

void advance(parser_T* parser)
{
	pop(&parser->stack);
}

token_T* factor(parser_T* parser)
{
	if (!strcmp(peek(&parser->stack)->type, TT_FLOAT) || !strcmp(peek(&parser->stack)->type, TT_INT))
	{
		return pop(&parser->stack);
	}
	else if (!strcmp(peek(&parser->stack)->type, TT_RPAREN))
	{
		advance(parser);
		token_T* expression = expr(parser);
		if (!strcmp(peek(&parser->stack)->type, TT_LPAREN))
		{
			return expression;
		}
		else
		{
			printf("INVALID SYNTAX: EXPECTED A PARANTHESIS");
			printf("\nPress any key to exit\n");
			getchar();
			exit(-1);
		}
	}
	else
	{
		printf("INVALID SYNTAX: EXPECTED A INT/FLOAT TOKEN");
		printf("\nPress any key to exit\n");
		getchar();
		exit(-1);
	}
}

token_T* term(parser_T* parser)
{
	token_T* right = factor(parser);
	if (isEmpty(parser->stack))
	{
		// oh boi long line warning
		if (strcmp(peek(&parser->stack)->type, TT_PLUS) && strcmp(peek(&parser->stack)->type, TT_MINUS) && strcmp(peek(&parser->stack)->type, TT_DIV) && strcmp(peek(&parser->stack)->type, TT_MUL) && strcmp(peek(&parser->stack)->type, TT_LPAREN) && strcmp(peek(&parser->stack)->type, TT_RPAREN))
		{
			printf("INVALID SYNTAX: EXPECTED A +,-,*,/ TOKEN");
			printf("\nPress any key to exit\n");
			getchar();
			exit(-1);
		}

		while (!strcmp(peek(&parser->stack)->type, TT_MUL) || !strcmp(peek(&parser->stack)->type, TT_DIV))
		{
			token_T* op = pop(&parser->stack);
			token_T* left = factor(parser);

			if (!strcmp(op->type, TT_MUL))
			{
				// TODO: Multiplication and division
			}
		}
	}
}

token_T* expr(parser_T* parser);
void parse(parser_T* parser);