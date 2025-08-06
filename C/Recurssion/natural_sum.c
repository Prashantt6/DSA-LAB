#include <stdio.h>

long int sum(int n)
{
    if (n == 1)
        return 1;
    else
        return n + sum(n - 1);   
} 

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int result = sum(n);
    printf("Sum = %ld\n", result);
    return 0;
}