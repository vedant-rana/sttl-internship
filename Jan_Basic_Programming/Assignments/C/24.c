#include<stdio.h>
// GCD of 2 Nums
int main(){
    int n1, n2, cn, gcd;

    printf("Enter 2 Numbers : ");
    scanf("%d %d", &n1, &n2);

    if(n1>n2){
        cn=n2;
    }else{
        cn=n1;
    }

    while(cn>0){
        if(n1%cn == 0 && n2%cn ==0){
            gcd = cn;
            break;
        }
        cn--;
    }

    printf("gcd(%d, %d) : %d", n1, n2, cn);
 return 0;
}