#include <stdio.h>
#include <stdlib.h>
#include <lexer.h>

int main()
{
	char str[512];
	printf("hethor > ");
	//gets(str);
	scanf("%[^\n]%*c", str);		// because C is so mad that i use gets it's spewing out warnings like crazy
	lexer_T* lexer = initLexer(str);
	makeTokens(lexer);
	printTokens(lexer);
	getchar();
	return 0;
}