#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string block = "########";
    printf("Height: ");
    int height;
    scanf("%d", &height);
    
    while (height < 1 || height > 8)
    {
        printf("Height: ");
        scanf("%d", &height);
    }

    for (int num = 1; num <= height; num++)
    {
        int width = height;
        printf("%*.*s", width, num, block);
        width = num;
        printf("%*.*s\n", width + 2, num, block);
    }

    return 0;
}
