#include<stdio.h>
int main(){
    int num, sum = 0;
     printf("Enter the Number : ");
    scanf("%d", &num);

    for(int i=1; i<=num; i++){
        if(num/i == 0){
            sum+=i;
        }
    }

    if(sum == num){
        printf("%d is a perfect Number. ", num);
    }else{
        printf("%d is not a perfect Number. ", num);
    }

 return 0;
}