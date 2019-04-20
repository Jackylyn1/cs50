#include <stdio.h>
#include <cs50.h>
void valid(long int number);
long int sum_every2(long int number, int start);
    
int main(void)
{
    long int number;
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);
    valid(number);
}

void valid(long int number)
{
    int start_nums;
    bool is_valid = false;
    int valid_num = sum_every2(number, 1);
    valid_num += sum_every2(number, 10);
    if (valid_num % 10 == 0)
    {
        for (long i = 12; i < 16; i++)
        {
            long int rest_mode = 10;
            for (int j = i - 2; j > 0; j--)
            {
                rest_mode *= 10;
            }
            long int rest = number / rest_mode;
            if (rest >= 10 && rest < 100)
            {
                if (rest >= 40 && rest < 50)
                {
                    printf("VISA\n");
                    is_valid = true;
                }  
                else if (rest == 34 || rest == 37)
                {
                    printf("AMEX\n");
                    is_valid = true;
                }
                else if (rest > 50 && rest < 56)
                {
                    printf("MASTERCARD\n");
                    is_valid = true;
                }
            }
        }
    }
    if (is_valid == false)
    {
        printf("INVALID\n");     
    }
}

long int sum_every2(long int number, int start)
{
    int summand;
    int sum = 0;
    number /= start;
    while (number > 0)
    {
        summand = number % 10;
        summand *= (start == 10) ? 2 : 1;
        number /= 100;
        if (start == 10)
        {
            while (summand > 9)
            {
                sum += summand % start;
                summand /= 10;
            }
            sum += summand % start;
        }
        else
        {
            sum += summand;
        }
    }
    return sum;
}
