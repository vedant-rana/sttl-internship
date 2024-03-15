#include<stdio.h>
int main(){
    char ch;
    printf("Enter Character : ");
    scanf(" %c", &ch);

    printf("ASCII of %c is %d.", ch, (int)ch);
 return 0;
}