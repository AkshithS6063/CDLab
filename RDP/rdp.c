#include <stdio.h>
#include <string.h>

int error = 0;
char str[20];
int x = 0;

void S();
void L();
void L1();

void L() {
	S();
	L1();
}

void L1(){
	if(str[x] == ','){
		x++;
		S();
		L1();
	}
}

void S()
{
  
    if (str[x] == '(')
    {
        x++;
		L();
    
    	if (str[x] == ')')
    	{
		    	x++;
		}
		else { error = 1;}
	}
    if (str[x] == 'a')
    {
        x++;
    }
    
}

void main()
{

    printf("input\n");
    fgets(str, 20, stdin);
    int strl = strlen(str);
    S();
    
    if (x == strl-1 && error == 0)
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }
}
