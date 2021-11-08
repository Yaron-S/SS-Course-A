#include <stdio.h>
#include "NumClass.h"

int isArmstrong(int x){
    int sum = 0, y, z = x;
    while(x>0){
        y = x%10;
        sum+=(y)*(y)*(y);
        x = x/10;
    }
    if(sum == z) return 1;
    return 0;          
}
int isPalindrome(int x){
    int sum = 0, y, z = x;
    while(x>0){
        y = x%10;
        sum = sum*10+y;
        x = x/10;
    }
    if(sum == z) return 1;
    return 0;
}