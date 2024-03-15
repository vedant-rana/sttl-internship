
#include <stdio.h>

int main() {
    int a,b,temp=0;
    printf("Enter 1st Num : ");
    scanf("%d", &a);
    printf("Enter 2nd Num : ");
    scanf("%d", &b);
   
   temp = b;
   b=a;
   a=temp;
   
    printf("1st Num : %d\n", a);
     printf("2nd Num : %d", b);
    
    return 0;
}