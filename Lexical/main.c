#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEYWORD 1
#define OPERATOR 2
#define IDENTIFIER 3
#define FUNCTION 4

char KEY[20][20];
char OP[20][20];
char ID[20][20];
char FUNC[20][20];

int key = 0, op = 0, id = 0, fn = 0;

void push(char data[20],int type){
    switch (type)
    {
    case KEYWORD:
        strcpy(KEY[key++], data);
        break;
    case OPERATOR:
        strcpy(OP[op++], data);
        break;
    case IDENTIFIER:
        strcpy(ID[id++], data);
        break;
    case FUNCTION:
        strcpy(FUNC[fn++], data);
        break;

    default:
        break;
    }
}

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

void main(){
    FILE *fptr;

    fptr = fopen("file", "r");
    char ch,data[20];
    if(fptr == NULL){
        printf("No Such File\n");
    }
    while (fscanf(fptr, "%s", data) != EOF)
    {
        // printf("%s",data);
        if(isKey(data)){
            push(data, KEYWORD);
        }
        else if(isOp(data)){
            push(data, OPERATOR);
        }
        else if(isFn(data)){
            push(data, FUNCTION);
        }
        else{
            push(data, IDENTIFIER);
        }
    }

    printf("Keywords :----> ");
        for(int i=0; i<key; i++) {
        printf("%s ", KEY[i]);
    }
    printf("\n");
    printf("Functions :---> ");
    for (int i = 0; i < fn; i++)
    {
        printf("%s ", FUNC[i]);
    }
    printf("\n");
    printf("Operators :---> ");
    for (int i = 0; i < op; i++)
    {
        printf("%s ", OP[i]);
    }
    printf("\n");
    printf("Identifiers :-> ");
    for (int i = 0; i < id; i++)
    {
        printf("%s ", ID[i]);
    }
    printf("\n");
}