#include<stdio.h>
int main(){
    int a, b=0, sum=0; 
    printf("Enter Num : ");
    scanf("%d", &a);
    b=a;

    while(b>0){
        sum = sum + (b%10);
        b/=10;
    }
    printf("Sum : %d", sum);
 return 0;
}