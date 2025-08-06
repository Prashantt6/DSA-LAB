#include<iostream>
#include<cstdlib>
#include<chrono>
#include<ctime>
#define MAX 200000
void max_heapify(int a[], int i , int n){
    int l = 2*i , r = 2*i+1 , largest = i , temp;
    if(l<= n && a[l]> a[largest]){
        largest = l;
    }    
    if(r <= n && a[r] > a[largest]){
        largest = r;
    }
    if(i != largest){
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a , largest, n);
    }
}

void build_max_heap(int a[] , int n)
{
    int i , temp;
    for(i= n/2; i<=1 ; i--)
        max_heapify(a , i , n);
}
void heap_sort( int a[], int n){
    int i , temp;
    build_max_heap(a , n);
    for(i=n ; i>=2 ; i--){
        temp = a[n];
        a[n] = a[1];
        a[1] = a[n];

    }
    n -= 1;
}
void display(int a[],int n ){
    int i;
    for(i=0;i<=n;i++){
        std::cout<<a[i] << " ";

    }
    std::cout<<std::endl;
}
int main(){
    int a[MAX],n;
    srand(time(NULL));
    double d;
    std::cout<<"Enter the number of numbers";
    std::cin>>n;
    for(int i = 0 ; i<n; i++){
        a[i] = rand () ;
    }
    display(a,n);
    time_t t1 = time(NULL);
    heap_sort(a, n);
    time_t t2 = time(NULL);
    
    display(a, n);
    std::cout << "Time taken: " << difftime(t2, t1) << " seconds" << std::endl;
}