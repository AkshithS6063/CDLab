#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.c"
#include "push.c"

void printfinctions(){
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
