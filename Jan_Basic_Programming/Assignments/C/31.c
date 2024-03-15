#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// Anagrams
char *sortedStr(char str[], int len)
{
    char *sorted = (char *)malloc((len + 1) * sizeof(char));
    char temp;

    for (int i = 0; i < len; i++)
    {
        sorted[i] = str[i];
    }

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (sorted[i] > sorted[j])
            {
                temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }

    sorted[len] = '\0';
    return sorted;
}

int main()
{
    char str1[30], str2[30];
    bool flag = false;

    printf("Enter the First String : ");
    scanf(" %s", &str1);
    printf("Enter the second String : ");
    scanf(" %s", &str2);

    if (strlen(str1) != strlen(str2))
    {
        printf("Given String are not Anagram.");
    }
    else
    {
        char *sortedStr1 = sortedStr(str1, strlen(str1));
        char *sortedStr2 = sortedStr(str2, strlen(str2));

        for (int i = 0; i < strlen(str1); i++)
        {
            if (sortedStr1[i] != sortedStr2[i])
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            printf("Given String are not Anagram.");
        }
        else
        {
            printf("Given String are Anagram.");
        }
    }

    return 0;
}