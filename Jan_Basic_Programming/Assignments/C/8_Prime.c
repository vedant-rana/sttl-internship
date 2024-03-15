
#include <stdio.h>
#include <stdbool.h>

int main() {
    int a;
    bool flag=false;
    printf("Enter Num : ");
    scanf("%d", &a);
    
    for(int i=2; i<(a/2); i++){
        if(a%i == 0){
            flag=true;
        }
    }
    
    if(flag == true){
        printf("%d is not a prime num.", a);
    }else{
        printf("%d is a prime num.", a);
    }
    
    return 0;
}