#import <stdio.h>
#import <cs50.h>
#import <math.h>
float min_coins(float change, float coin);
int this_coins_max(float change, float coin);
float this_coins_rest(float change, float coin);

int main(void)
{
    float change;
    do
    { 
        change = get_float("Change owed: ");
    }
    while (change <= 0);  
    int max_coins = this_coins_max(change, 0.25);
    change = this_coins_rest(change, 0.25);
    max_coins += this_coins_max(change, 0.1);
    change = this_coins_rest(change, 0.1);
    max_coins += this_coins_max(change, 0.05);
    change = this_coins_rest(change, 0.05);
    max_coins += this_coins_max(change, 0.01);
    change = this_coins_rest(change, 0.01);
    printf("%i\n", max_coins);
}

int this_coins_max(float change, float coin)
{
    float change_num = change / coin;
    return (int) change_num;
}

float this_coins_rest(float change, float coin)
{
    int change_now = (int) round(change * 100);
    int coin_now = (int) round(coin * 100);
    int rest = round(change_now % coin_now);
    return (float) rest / 100;
}
