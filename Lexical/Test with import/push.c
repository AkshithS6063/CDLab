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