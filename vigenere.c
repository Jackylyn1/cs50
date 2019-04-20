#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    bool error = 1;
    if (argc == 2)
    {
        error = 0;
        string keyword = argv[1];
        for (int i = 0, n = strlen(keyword); i < n; i++)
        {
            if (!isalpha(keyword[i]))
            {
                error = 1;
            }
        }
        
        if (!error)
        {
            int num_plus;
            int key;
            int cnt = 0;
            string text = get_string("plaintext: ");
            for (int i = 0, n = strlen(text); i < n; i++)
            {
                //find out what the actual key is
                key =  shift(keyword[cnt % strlen(keyword)]);
                num_plus = 0;
                if (islower(text[i]))
                {
                    num_plus = 97;
                }
                else if (isupper(text[i]))
                {
                    num_plus = 65;
                }
                if (num_plus)
                {
                    text[i] = (text[i] + key - num_plus) % 26 + num_plus;
                    cnt++;
                }
            }
            printf("ciphertext: %s\n", text);
            return 0;
        }
    }
    
    if (error == 1)
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
}

int shift(char c)
{
    int num_plus = 0;
    if (islower(c))
    {
        num_plus = 97;
    }
    else if (isupper(c))
    {
        num_plus = 65;
    }
    if (num_plus)
    {
        c -= num_plus;
    }
    return c;
}
