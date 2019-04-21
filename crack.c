#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>
#include <ctype.h>
string allowed_signs(void);
string check_pw(int max_pos, int pos, char salt[], string hash, string before);

int main(int argc, string argv[])
{
    bool error = true;
    if (argc == 2)
    {
        char salt[2]; 
        salt[0] = argv[1][0];
        salt[1] = argv[1][1];
        string pw = check_pw(0, 0, salt, argv[1], "");
        if (pw)
        {    
            printf("%s\n", pw);
            //crypt(string,salt);
            error = false;
        }
    }
    if (error)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    
}

string check_pw(int max_pos, int pos, char salt[], string hash, string before)
{
    string allowed = allowed_signs();
    string pw = malloc(max_pos + 1);
    strcpy(pw, before);
    for (int i = 0, n = strlen(allowed); i < n; i++)
    {   
        pw[pos] = allowed[i];
        string new_hash = crypt(pw, salt);
        printf("%s\n", pw);
        if (!strcmp(new_hash, hash))
        {
            return pw;
        }
        
        if (max_pos > pos)
        {
            string pw_other = check_pw(max_pos, pos + 1, salt, hash, pw);
            if(pw_other)
            {
                return pw_other;
            }
        }
    }
    
    if (max_pos < 4)
    {
        string pw_later = check_pw(max_pos + 1, 0, salt, hash, "");
        if(pw_later)
        {
            return pw_later;
        }
    }
    return false;
}

string allowed_signs(void)
{
    string allowed = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    return allowed;
}
