
#include <stdio.h>

int main() {
    int a,b,fact=1;
    printf("Enter Num : ");
    scanf("%d", &a);
   
    b=a;
    while(b>0){
        fact=fact*b;
        b--;
    }
    
     printf("%d! : %d", a, fact);
    return 0;
}