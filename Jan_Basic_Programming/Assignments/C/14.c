#include<stdio.h>
int main(){
    int a, b;
    char op;
    printf("Basic Calculator : \nEnter 2 Numbers : \n");
    printf("Num1 : ");
    scanf("%d", &a);

    printf("Num1 : ");
    scanf("%d", &b);
  

    printf("Enter Operation '+', '-', '/', '*' : ");
    scanf(" %c", &op);

    switch (op)
    {
    case '+':
        printf("Sum : %d", a+b);
        break;

        case '-':
        printf("subtraction : %d", a-b);
        break;

        case '/':
        printf("Division : %f", ((float)a)/b);
        break;

        case '*':
        printf("multiplication : %d", a*b);
        break;
    
    default:
    printf("Enter Valid Operator");
        break;
    }

 return 0;
}