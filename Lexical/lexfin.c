
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"
#include "push.c"

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

    printf("Keywords are -> ");
        for(int i=0; i<key; i++) {
        printf("%s ", KEY[i]);
    }
    printf("\n");
    printf("Functions -> ");
    for (int i = 0; i < fn; i++)
    {
        printf("%s ", FUNC[i]);
    }
    printf("\n");
    printf("Operators -> ");
    for (int i = 0; i < op; i++)
    {
        printf("%s ", OP[i]);
    }
    printf("\n");
    printf("Identifiers -> ");
    for (int i = 0; i < id; i++)
    {
        printf("%s ", ID[i]);
    }
    printf("\n");
}