#include <stdio.h>
#include <string.h>

int error = 0;
char str[20];
int x = 0;

void S();
void A();
void B();
void C();

void A(){
	if(str[x]=='a'){
		x++;
		A();
		if(str[x]=='b'){
			x++;
		}
		else{
			error = 1;
		}
	}
	else{
		C();
	}
}

void C(){
	if(str[x]=='e'){
		x++;
		C();
	}
}

void B(){
	
	if(str[x]=='c'){
		x++;
		B();
	}
	else{
		if(str[x]=='d'){
			x++;
		}
	}
}

void S()
{
  
    A();
    B();
    C();
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

