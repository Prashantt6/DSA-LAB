#include <stdio.h>
#define MAX 100

long int table[MAX] = {0};

long int Fibo(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
    {
        if (table[n] == 0) //value is not in table
        {
            table[n] = Fibo(n - 1) + Fibo(n - 2);
        }
        return table[n];
    }
}

int main()
{
    int n, num;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    num = Fibo(n); 
    printf("The required Fibonacci term is %ld", num);  
    return 0;
}