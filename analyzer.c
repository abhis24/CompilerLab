#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
int isKeyword(char buffer[]){
    char keywords[35][10] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while","printf"};
    int i, flag = 0;
    
    for(i = 0; i < 32; ++i){
        if(strcmp(keywords[i], buffer) == 0){
            flag = 1;
            break;
        }
    }
    
    return flag;
}
 
int main(){
    char ch, buffer[15], operators[] = "+-*/!=%";
    FILE *fp;
    int i,j=0;
    
    fp = fopen("program.txt","r");
    
    if(fp == NULL){
        printf("error while opening the file\n");
        exit(0);
    }
    
    while((ch = fgetc(fp)) != EOF){

           for(i = 0; i < 7; ++i){ // checks for operators
               if(ch == operators[i])
                   printf("%c is operator\n", ch);
           }
           
           if(isalnum(ch)){  // storing the word in buffer
               buffer[j++] = ch;
           }

           else if(j != 0){ // condition for checking the accumulated word
                   buffer[j] = '\0';
                   j = 0; // resetting j tp zero
                                      
                   if(isKeyword(buffer) == 1)
                       printf("%s is keyword\n", buffer);
                   else
                       printf("%s is indentifier\n", buffer);
           }
           
    }
    
    fclose(fp);
    
    return 0;
}
