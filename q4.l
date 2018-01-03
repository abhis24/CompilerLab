%{#include<iostream.h>
int count=0;
char ch=0;
%}
digit[0-9]
letter[a-zA-Z_]

%%
{letter}({letter}|{digit})* { count++;}
("int")|("void")|("return")|("include") {printf("%s is a keyword\n",yytext);}

%%
int main()
{

	yyin=fopen("program1.c","r");

 yylex();
 printf("count: %d",count);
} 
int yywrap()
{
return 1;
}

 