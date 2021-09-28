#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char num;
    FILE *fptr;

    char data[100];
    fgets(data,100,stdin);

    fptr = fopen("file.txt", "w");
    if(fptr == NULL){
        printf("FAILED to open!!!");
    }
    else{
        printf("File opened \n");

        if(strlen(data)>0){
            fputs(data, fptr);
            // fputs("\n", fptr);
        }
        fclose(fptr);
        printf("Entered into data\n");
        printf("file closed\n");
    }

    return 0;
}