#include <cs50.h>
#include <stdio.h>
void bricks(int n);
void print_signs(int i, char c);

int main(void)
{
    int height;
    do
    { 
        height = get_int("What is the pyramides height? (positive number between 1 and 8)\n");
    }
    while (height < 1 || height > 8);
    bricks(height);
}

void bricks(int n)
{
    //add rows
    for (int i = 1; i <= n; i++)
    {
        print_signs(n - i, ' ');
        print_signs(i, '#');
        printf("  ");
        print_signs(i, '#');
        printf("\n");
    }
}

void print_signs(int i, char c)
{
    //add cols
    for (int j = 0; j < i; j++)
    {
        printf("%c", c);
    }
}
