#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isKey(char data[20])
{
    char keywords[32][16] = {"auto","break","case","char","const",    
    "continue","default","do","double","else","enum","extern",       
    "float","for","goto","if","int","long","register","return",      
    "short","signed","sizeof","static","struct","switch","typedef",  
    "union","unsigned","void","volatile","while"
  };
    int i, flag = 0;
    for (i = 0; i < 32; i++)
    {
        if (strcmp(data, keywords[i]) == 0)
        {
            return 1;
        }
    }
  return 0;
}

int isOp(char data[20]){
    char operators[6][16] ={"+","-","%","=","*","/"};
    int i, flag = 0;
    for (i = 0; i < 6; i++)
    {
        if (strcmp(data, operators[i]) == 0)
        {
            return 1;
        }
    }
  return 0;
}

int isFn(char data[20]){
    int len = strlen(data);
    if (data[len - 1] == ')' && data[len - 2] == '(')
    {
        return 1;
    }
  return 0;
}