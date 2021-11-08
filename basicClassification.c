#include <stdio.h>
#include "NumClass.h"

int isPrime(int x)
{
    for(int i = 2; i*i<=x; i++) if(x%i == 0) return 0;
    return 1;
}
int factorial(int r){  
    int sum=1;  
    for(int i=1;i<=r;i++)  
    {  
        sum=sum*i;  
    }  
    return sum;  
}
int isStrong(int n){
    int sum=0,k=n,r; 
    while(k!=0){  
        r=k%10;  
        int f=factorial(r);  
        k=k/10;  
        sum=sum+f;  
    }  
    if(sum==n)  
        return 1;
    return 0; 
}


