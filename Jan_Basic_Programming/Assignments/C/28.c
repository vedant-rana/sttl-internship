#include<stdio.h>
int main(){
    char str[] = "abcdefghij";
    int len = sizeof(str)/sizeof(str[0]) -1;
    int countOfVowel=0, countOfConsonants=0;
    
    for(int i=0; i<len; i++){
        if(str[i]=='a' ||str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u' ){
            countOfVowel+=1;
        }
    }
    countOfConsonants=len-countOfVowel;

    printf("Numbers of Vowels : %d\n", countOfVowel);
    printf("Numbers of Consonants : %d", countOfConsonants);

 return 0;
}