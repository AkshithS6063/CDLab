#include <stdio.h>
#include <string.h>

int error = 0;
char str[20];
int x = 0;

void E();
void T();
void F();
void E1();
void T1();

void F()
{
    
    if (str[x] == '(')
    {
        x++;
		E();
    
    	if (str[x] == ')')
    	{
		    	x++;
		}
		else { error = 1;}
	}
    else if (str[x] == 'i')
    {
        x++;
    }
    else { error = 1;}
}

void T1()
{
    
    if (str[x] == '*')
    {
        x++;
        F();
        T1();
        
    }
}

void T()
{
    
    F();
    T1();
}

void E1()
{
    if (str[x] == '+')
    {
        x++;
        T();
		E1();
    }
}

void E()
{
  
    T();
    E1();
}

void main()
{

    printf("input\n");
    fgets(str, 20, stdin);
    int strl = strlen(str);
    E();
    
    if (x == strl-1 && error == 0)
    {
        printf("Accepted\n");
    }
    else
    {
        printf("Rejected\n");
    }
}
