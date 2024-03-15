#include<stdio.h>
// Reverse String
int main(){
    char str[]="abcdef", temp;
    int len = sizeof(str)/sizeof(str[0]) -1;

    for(int i=0; i<len/2; i++){
        temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;
    }

    printf("Reverse String : %s", str);
 return 0;
}