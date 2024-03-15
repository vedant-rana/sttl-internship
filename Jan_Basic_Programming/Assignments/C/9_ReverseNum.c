
#include <stdio.h>
#include <stdbool.h>

int main() {
    int a, temp=0;
    printf("Enter Num : ");
    scanf("%d", &a);
    
   while(a>0){
       temp=(temp* 10)+(a%10);
       a=a/10;
   }
   printf("Reverse: %d " , temp);
    
    return 0;
}