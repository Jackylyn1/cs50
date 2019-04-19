#include <cs50.h>
#include <stdio.h>
void bricks(int n);
void printSigns(int i, char c);
    
int main(void)
{
    int height;
    do
    { 
        height = get_int("What is the pyramides height? (type in a positive number between 1 and 8 )\n");
     }
    while(height < 1 || height > 8);
    
    bricks(height);
}

void bricks(int n)
{
    for (int i = 0; i < n; i++)
    {
        printSigns(7 - i,' ');
        printSigns(i,'#');
        printf("\n");
    }
}

void printSigns(int i, char c)
{
     for (int j = 0; j <= i; j++)
      {
          printf("%c", c);
      }
}
