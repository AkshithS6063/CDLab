#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char num;
    FILE *fptr;

    char data[100];
    scanf("%s",data);

    fptr = fopen("file.txt", "w");
    if(fptr == NULL){
        printf("FAILED to open!!!");
    }
    else{
        printf("File opened \n");

        if(strlen(data)>0){
            fputs(data, fptr);
            fputs("\n", fptr);
        }
        fclose(fptr);
        printf("Success\n");
        printf("file closed\n");
    }

    return 0;
}