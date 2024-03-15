
#include <stdio.h>

int main() {
    int a,b,fact=1, first=0, second=1, third=0;
    printf("Enter Num : ");
    scanf("%d", &a);
    printf("%d, %d, ", first, second);
    b=a;
    while(b>2){
        third = first+second;
        printf("%d, ", third);
        first=second;
        second = third;
        b--;
    }
    
    return 0;
}