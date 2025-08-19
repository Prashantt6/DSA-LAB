#include <stdio.h>

int largest( int a [] , int n ){
    int max = a[0];
    int i;
    for(i = 0 ; i< n ; i++){
        if(a[i]> max){
            max = a[i];
        }
    }
    return max;
}
void countingsort(int a [], int n , int max){
    
    int* count = (int*) calloc(max+1, sizeof(int));
    int* b = (int*) calloc(n+1, sizeof(int));
    for(int i = 0 ; i<= max ; i++){
        count[i] = 0;
    }
    for(int i = 0 ; i<n ; i++){
        count[a[i]]++;
    }
    for(int i = 1 ; i <= max; i++)
    {
        count[i] = count[i] + count[i-1];
    }
    for(int j = n-1 ; j>= 0; j--){
        b[--count[a[j]]] = a[j];
    }
    for(int i = 0 ; i< n ; i++){
        a[i] = b[i];
    }
}
void display(int a [], int n ){
    int i ;
    for(i = 0 ; i < n ; i++ ){
        printf("%d\t", a[i]);
    }
}
int main()
{
    int a [] = {100,101,200,8,1,3,5,69,45,34};
    int n = sizeof(a)/sizeof(a[0]);
    printf("\n The list of numbers before sorting is : ");
    display(a, n);
    int max = largest(a,n);
    countingsort(a , n , max);
    printf("\n After sorting :");
    display(a, n);
}