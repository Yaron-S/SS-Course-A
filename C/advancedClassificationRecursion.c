#include <stdio.h>
#include <math.h>
#include "NumClass.h"
int checkArmstrong(int x, int numOfDigits){
    if (x < 10)
    {
        return (int)(pow(x, numOfDigits));
    }
    int y = (int)(pow(x % 10, numOfDigits));
    return (y + checkArmstrong(x / 10, numOfDigits));
}

int isArmstrong(int x)
{
    int numOfDigits = (int)log10(x) + 1;
    if (x == checkArmstrong(x, numOfDigits))
    {
        return 1;
    }
    return 0;
}

    int reverse(int x){
        int digit =  (int)log10(x);
        if(x == 0) return 0;
        return (((x%10) * pow(10, digit)) + reverse(x/10));
    }    
    int isPalindrome(int x){
        if(x == reverse(x)) return 1;
        return 0;
    }

