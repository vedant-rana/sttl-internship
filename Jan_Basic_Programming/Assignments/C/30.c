#include<stdio.h>
int main(){
    char str[50];
    int i=0, len=0;

    printf("Enter String : ");
    scanf(" %s", str);
    
    while(str[i] != '\0'){
        len++;
        i++;
    }

    printf("Length of String : %d", len);
 return 0;
}