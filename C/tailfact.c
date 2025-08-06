#include <stdio.h>

long int tailfact(int n, int a)
{
    if(n == 0)
        return a;
    else
        return tailfact(n-1, n*a);
}

int main()
{
    int n, a = 1;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int result = tailfact(n,a);
    printf("Factorial of %d is %ld.", n, result);
    return 0;
}