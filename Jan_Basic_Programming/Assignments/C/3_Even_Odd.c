
#include <stdio.h>

int main() {
    int a;
    printf("Enter Num : ");
    scanf("%d", &a);
    
    if(a%2 == 0){
        printf("%d is Even Num.", a);
    }else{
            printf("%d is odd Num.", a);
    }
    
    return 0;
}