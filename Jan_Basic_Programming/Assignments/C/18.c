#include<stdio.h>
// Simple INterest

int main(){
    int p;
    float r, n;

    printf("Enter Principal : ");
    scanf("%d", &p);
     printf("Enter Rate of Interest : ");
    scanf("%f", &r);
     printf("Enter Number of Years : ");
    scanf("%f", &n);

    float interest = (p*r*n)/100;

    printf("Simple INterst : %f", interest);
 return 0;
}