#include <stdio.h>
#include <time.h>

void TOH(int n, char src, char dst, char tmp)
{
    if (n == 1)
        printf("Move disc %d from %c to %c\n", n, src, dst);
    else
    {
        TOH(n-1, src, tmp, dst);
        printf("Move disc %d from %c to %c\n", n, src, dst);
        TOH(n-1, tmp, dst, src);
    }    
}

int main()
{
    int n;
    time_t start, end;
    double seconds;

    start = time(NULL);
    printf("Enter the value of n: ");
    scanf("%d", &n);
    TOH(n, 'A', 'C', 'B');
    end = time(NULL);
    seconds = difftime(end, start);
    printf("%f seconds", seconds);
    return 0;
}