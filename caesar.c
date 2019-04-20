#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    bool error = 1;
    if (argc == 2)
    {
        int key = atoi(argv[1]);
        if (key)
        {
            int num_plus;
            string text = get_string("plaintext: ");
            for (int i = 0, n = strlen(text); i < n; i++)
            {
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
                }
            }
            printf("ciphertext: %s\n", text);
            return 0;
        }
    }
    
    if (error == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
