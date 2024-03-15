#include<stdio.h>
// String Concatation
int main(){
    char s1[] ="hello";
    char s2[] = "world";

    int len1 =  sizeof(s1)/sizeof(s1[0]) -1 ,len2 = sizeof(s1)/sizeof(s1[0]) -1 ;
    int totalLen = len1 + len2;
    char newstr[totalLen];

    for(int i=0; i<totalLen; i++){
        if(i<len1){
            newstr[i]=s1[i];
        }else{
            newstr[i]=s2[i-len1];
        }
    } 

    newstr[totalLen] = '\0';
    printf("Conconated String : %s", newstr);
 return 0;
}