%{
#include<stdio.h>
%}

%%

\/\/.* {};
\/\*(.*\n)*.*\*\/ {};
%%

main()
{
yyin=fopen("program.c","r");
yylex();
}

int yywrap()
{
return 1;
}