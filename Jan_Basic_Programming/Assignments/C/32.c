#include <stdio.h>
int main()
{
    char str[50];
    int i = 0, words = 1;

    printf("Enter the Sentence : ");
    scanf(" %[^\n]", str);

    while (str[i] != '\0')
    {
        if ((int)str[i] == 32 && (int)str[i + 1] != 32)
        {
            words++;
        }
        i++;
    }

    printf("Words in Sentence : %d", words);
    return 0;
}