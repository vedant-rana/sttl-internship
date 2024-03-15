#include<stdio.h>
//Fehrenheit to Celsius

int main(){
    float cel, fehren;
    printf("Enter Temperature in Fehrenheit : ");
    scanf("%f", &fehren);

    cel = (fehren - 32) * (5.0/9);

    printf("Celsius : %0.2f", cel);
 return 0;
}