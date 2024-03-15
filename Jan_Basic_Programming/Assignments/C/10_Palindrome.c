#include <stdio.h>
#include <stdbool.h>

int main()
{
    char name[] = "abcdcb";
    int len = sizeof(name)/sizeof(name[0]);
    bool flag=false;

    for(int i=0; i<len/2; i++){
        if(name[i] != name[len-1]){
            flag =true;
            break;
        }
    }

    if(flag){
        printf("Not Palindrome");
    }else{
        printf("Palindrome");
    }
    return 0;
}