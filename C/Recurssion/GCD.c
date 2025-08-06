#include <stdio.h>

long int GCD(int a, int b)
{
    if(b==0)
        return a;
    else
        return  GCD(b , a%b);
}

int main()
{
    int a, b, result;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of a: ");
    scanf("%d", &b);
    result = GCD (a, b);
    
    printf("The GCD of %d and %d is %ld.", a, b, result);
    return 0;
}