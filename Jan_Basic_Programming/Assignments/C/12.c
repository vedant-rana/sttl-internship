#include<stdio.h>
// Decimal to Binary
int main(){
    int decimal;
    int binary[50];

    printf("Enter the decimal Number : ");
    scanf("%d", &decimal);
    
    int i=0;
    while(decimal>0){
        binary[i++]=decimal % 2;
        decimal/=2;
    }

    for(int j=i-1; j>=0; j--){
        printf("%d ", binary[j]);
    }
 return 0;
}