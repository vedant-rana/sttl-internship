#include <stdio.h>
// Factorization of Numbers

int main()
{
    int num;
    printf("Enter the Number : ");
    scanf("%d", &num);

    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            printf("%d, ", i);
        }
    }

    printf("%d, ", num);

    return 0;
}