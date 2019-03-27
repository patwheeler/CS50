#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    char salt[3];
    char hash[256];
    char alphabet[256];
    char password[6];
    string argument = argv[1];
    strncpy(salt, argument, 2);
    salt[2] = 0;
    
    for (int i = 0; i < strlen(argument); i++)
    {
        hash[i] = argument[i];
    }
   
    for (int i = 'A'; i <= 'z'; i++)
    {
        password[0] = i;
        password[1] = '\0';
        if (strcmp(crypt(password, salt), hash) == 0)
        {
            printf("%s\n", password);
            return 0;
        }
        for (int j = 'A'; j <= 'z'; j++)
        {
            password[1] = j;
            password[2] = '\0';
            if (strcmp(crypt(password, salt), hash) == 0)
            {
                printf("%s\n", password);
                return 0;
            }
            for (int k = 'A'; k <= 'z'; k++)
            {
                password[2] = k;
                password[3] = '\0';
                if (strcmp(crypt(password, salt), hash) == 0)
                {
                    printf("%s\n", password);
                    return 0;
                }
                for (int l = 'A'; l <= 'z'; l++)
                {
                    password[3] = l;
                    password[4] = '\0';
                    if (strcmp(crypt(password, salt), hash) == 0)
                    {
                        printf("%s\n", password);
                        return 0;
                    }
                    for (int m = 'A'; m <= 'z'; m++)
                    {
                        password[4] = m;
                        password[5] = '\0';
                        if (strcmp(crypt(password, salt), hash) == 0)
                        {
                            printf("%s\n", password);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    
    printf("Password not found");
    return 1;
}
