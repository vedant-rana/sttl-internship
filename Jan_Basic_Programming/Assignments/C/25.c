#include<stdio.h>
// LCM of 2 Nums

int main(){
    int n1, n2, cn, lcm;

    printf("Enter 2 Numbers : ");
    scanf("%d %d", &n1, &n2);

    if(n1>n2){
        cn=n1;
    }else{
        cn=n2;
    }

    while(1){
        if(cn % n1 == 0 && cn % n2 ==0){
            lcm = cn;
            break;
        }
        cn++;
    }

    printf("lcm(%d, %d) : %d", n1, n2, cn);
 return 0;
}