#include <lexer.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

lexer_T* initLexer(char* text)
{
	lexer_T* lex = calloc(1, sizeof(struct LEXER_STRUCT));
	lex->text = text;
	lex->curPos = -1;
	lex->curTok = -1;
	
	advance(lex);
	return lex;
}

void advance(lexer_T* lexer)
{
	lexer->curPos++;
	if (lexer->curPos < strlen(lexer->text))
	{
		lexer->curChar = lexer->text[lexer->curPos];
	}
	else
	{
		lexer->curChar = '\0';
	}
}

void makeTokens(lexer_T* lexer)
{
	if (!strcmp(lexer->text, "quit"))
	{
		printf("Exiting TESTINGLOL\n");
		exit(0);
	}

	while (lexer->curChar != '\0')
	{
		if (isdigit(lexer->curChar) || lexer->curChar == '.')
		{
			makeNumber(lexer);
			continue;
		}
		switch(lexer->curChar)
		{
		case ' ':
			advance(lexer);
			break;
		case '\t':
			advance(lexer);
			break;
		case '+':
			advance(lexer);
			lexer->curTok++;
			lexer->tokens[lexer->curTok] = *initToken(TT_PLUS, "+");
			break;
		case '-':
			advance(lexer);
			lexer->curTok++;
			lexer->tokens[lexer->curTok] = *initToken(TT_MINUS, "-");
			break;
		case '*':
			advance(lexer);
			lexer->curTok++;
			lexer->tokens[lexer->curTok] = *initToken(TT_MUL, "*");
			break;
		case '/':
			advance(lexer);
			lexer->curTok++;
			lexer->tokens[lexer->curTok] = *initToken(TT_DIV, "/");
			break;
		case '^':
			advance(lexer);
			lexer->curTok++;
			lexer->tokens[lexer->curTok] = *initToken(TT_EXP, "^");
			break;
		case '%':
			advance(lexer);
			lexer->curTok++;
			lexer->tokens[lexer->curTok] = *initToken(TT_MOD, "%%");
			break;
		case '(':
			advance(lexer);
			lexer->curTok++;
			lexer->tokens[lexer->curTok] = *initToken(TT_LPAREN, "(");
			break;
		case ')':
			advance(lexer);
			lexer->curTok++;
			lexer->tokens[lexer->curTok] = *initToken(TT_RPAREN, ")");
			break;
		case '\n':
			lexer->curTok++;
			lexer->tokens[lexer->curTok] = *initToken(TT_EOF, "\n");
		default:
			printf("         ");
			for (int i = 0; i < lexer->curPos; i++)
			{
				printf(" ");
			}
			printf("^\nILLEGAL CHARACTER %c in position %d of file <stdin>", lexer->curChar, lexer->curPos);
			printf("\nPress any key to exit\n");
			getchar();
			exit(-1);
		}
	}

	lexer->curTok++;
	lexer->tokens[lexer->curTok] = *initToken(TT_EOF, "\0");
}

void makeNumber(lexer_T* lexer)
{
	char *number = calloc(1, sizeof(char) * 64);
	int isFloat = 0;
	int i;
	for (i = 0; isdigit(lexer->curChar) || lexer->curChar == '.'; i++)
	{
		if (lexer->curChar == '.')
		{
			isFloat++;
		}
		number[i] = lexer->curChar;
		advance(lexer);
	}
	number[i] = '\0';

	if (isFloat)
	{
		lexer->curTok++;
		lexer->tokens[lexer->curTok] = *initToken(TT_FLOAT, number);	
	}
	else
	{
		lexer->curTok++;
		lexer->tokens[lexer->curTok] = *initToken(TT_INT, number);	
	}

}
void printTokens(lexer_T* lexer)
{
	for (int i = 0; strcmp(lexer->tokens[i].type,TT_EOF); i++)
	{
		printToken(&(lexer->tokens[i]));
	}
}
token_T* getTokens(lexer_T* lexer)
{
	return lexer->tokens;
}