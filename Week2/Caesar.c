#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    int key = atoi(argv[1]);   
    if (key == 0)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    key %= 26;
    string plainTxt = get_string("plaintext: ");
    int n = strlen(plainTxt);
    int cipher[n];
    for (int i = 0; i < n; i++)
    {
        if ((plainTxt[i] >= 'a' && plainTxt[i] <= 'z') || (plainTxt[i] >= 'A' && plainTxt[i] <= 'Z'))
        {
            int num = (int) plainTxt[i];
            int sum = num + key;
            if (sum > 'z')
            {
                int remainder = sum - 'z';
                num = remainder + 'a' - 1;
                cipher[i] = num;
            }
            else if (sum > 'Z' && sum < 'a')
            {
                int remainder = sum - 'Z';
                num = remainder + 'A' - 1;
                cipher[i] = num;  
            }    
            else
            {
                num += key;
                cipher[i] = num;   
            }    
        }
        else
        {
            cipher[i] = plainTxt[i];
        }
    }
    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        printf("%c", cipher[i]);
    }
    printf("\n");
    
    return 0;
}
