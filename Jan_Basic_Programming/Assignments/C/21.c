#include<stdio.h>
//Armstrong number

int main(){
    int n, temp=0, t, sum=0;

    printf("Enter the Number : ");
    scanf("%d", &n);
    temp = n;

    while(temp>0){
        t=temp%10;
        sum = sum + (t*t*t);
        temp/=10;
    }

    if(sum == n){
        printf("%d is Armstrong Num.", n);
    }else{
        printf("%d is not an Armstrong Num.", n);
    }

 return 0;
}