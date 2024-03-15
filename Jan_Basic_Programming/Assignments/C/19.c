#include<stdio.h>
//Celsius to Fehrenheit

int main(){
    float cel, fehren;
    printf("Enter Temperature in Celsius : ");
    scanf("%f", &cel);

    fehren = (1.8 *cel) + 32;

    printf("Fehrenheit : %0.2f", fehren);
 return 0;
}