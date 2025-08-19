#include<stdio.h>
#include<stdlib.h>

void display(int a [], int n ){
    int i ;
    for(i = 0 ; i < n ; i++ ){
        printf("%d\t", a[i]);
    }
}

int max_elem(int a [], int n ){
    int max= a[0];
    int i ;
    for(i = 0 ; i< n; i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}
void counting_sort(int a[], int n , int pos){
    int count[10] = {0};
    int* b = (int*)calloc(n+1, sizeof(int));

    for(int i = 0 ; i < n ; i++)
    {
        count[(a[i]/pos) %10]++;
    }
    for(int i = 1 ; i <10 ; i++){
        count[i] = count[i] + count[i-1];
    }
    for(int j = n-1 ; j>= 0 ; j--)
    {
        b[--count[(a[j]/pos)%10]] = a[j];
    }
    for(int i = 0 ; i< n  ; i++)
    {
        a[i] = b[i];
    }

}

void radix(int a []  , int n ){
   int  max  = max_elem (a , n);
   for(int pos = 1 ; max/pos>0 ; pos*=10)
   {
    counting_sort( a ,  n ,  pos);
   }

}

int main(){
    
    int a [] = {100,101,200,8,1,3,5,69,45,34};
    int n = sizeof(a)/sizeof(a[0]);
    printf("\n The list of numbers before sorting is : ");
    display(a, n);
    radix(a , n);
    printf("\n After sorting : ");
    display(a, n);
}