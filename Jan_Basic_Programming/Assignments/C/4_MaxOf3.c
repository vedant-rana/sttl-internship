
#include <stdio.h>

int main() {
    int a,b,c;
    printf("Enter 1st Num : ");
    scanf("%d", &a);
    printf("Enter 2nd Num : ");
    scanf("%d", &b);
    printf("Enter 3rd Num : ");
    scanf("%d", &c);

   if(a>b){
       if(a>c){
           printf("%d is Largest Num.", a);
       }else{
           printf("%d is Largest Num.", c);
       }
   }else{
        if(b>c){
           printf("%d is Largest Num.", b);
       }else{
           printf("%d is Largest Num.", c);
       }
   }
    
    return 0;
}