#include<stdio.h>
#include<math.h>
//Binary to Decimal

int main(){
    int binary, decimal=0, i=0, temp=0, powOf2=1;
    printf("Enter Binary Num : ");
    scanf("%d", &binary);

    while(binary > 0){
        temp=binary%10;
        decimal = decimal + (temp * powOf2);
        powOf2*=2;
        binary/=10;
    }

    printf("Decimal : %d", decimal);
 return 0;
}