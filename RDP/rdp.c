#include <stdio.h>
#include <string.h>

char str[20];
int x = 0;
void E();
void T();
void F();
void E1();
void T1();

void F()
{
    printf("F\n");
    if (str[x] == '(')
    {
        x++;
    }
    if (str[x] == ')')
    {
        x++;
    }
    if (str[x] == 'i')
    {
        x++;
    }
}

void T1()
{
    printf("T1\n");
    if (str[x] == '*')
    {
        x++;
        if (str[x] == 'i')
        {
            F();
            T1();
        }
        else{
            printf("Invalid input");
        }
    }
}

void T()
{
    printf("T\n");
    F();
    T1();
}

void E1()
{
    if (str[x] == '+')
    {
        x++;
        if (str[x] == 'i')
        {
            T();
        }
        else
        {
            printf("Input invalid \n");
            x--;
        }
    }
}

void E()
{
    printf("E\n");
    T();
    E1();
}

void main()
{

    printf("input\n");
    fgets(str, 20, stdin);
    int strl = strlen(str) - 1;
    E();
    printf("%d", x);
    if (str[0] == str[strl-1])
    {
        printf("A\n");
    }
    else
    {
        printf("R\n");
    }
}