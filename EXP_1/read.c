#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
    FILE *fptr;

    char data[100],ch;

    int a=0, d=0, con=0, sym=0,v=0;
    
    fptr = fopen("file.txt", "r");
    printf("\n");

    if (fptr == NULL)
    {
        printf("NO such file");
    }
    else{  

        while ((ch=fgetc(fptr)) != EOF)
        {
            // check if alphabet
            if(isalpha(ch)){
                a = a + 1;

                // check if vowel
                if(ch == 'a'|| ch =='e'|| ch =='i'|| ch =='o'|| ch =='u' || 
                    
                    ch == 'A'|| ch =='E'|| ch =='I'|| ch =='O'|| ch =='U'){
                        
                        v = v + 1;
                }
                else{
                    con = con + 1;
                }
            }

            // check if digit
            else if (isdigit(ch))
            {
                d = d + 1;
            }

            // check if special symbol
            else{
                if(isspace(ch)){
                    continue;
                }
                else{
                    sym = sym + 1;
                }
            }

            printf("%c", ch);
            
        }
        
        printf("\n\n");
        printf("%d number of alphabets\n", a);
        printf("%d number of digits\n",d );
        printf("%d number of vowels\n",v );
        printf("%d number of consonents\n",con );
        printf("%d number of special symbols\n",sym );
        fclose(fptr);
    }
}