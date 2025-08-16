#include<stdio.h>

void display(int a [], int n){
    int i =0;
    for(i = 0 ; i< n; i++){
        printf("%d\t", a[i]);
    }
}

void insertion_sort(int a[], int n){
   
    for(int i=0; i<n; i++){
        int j = i-1;
        int element = a[i];

        while(j>=0 && element < a[j]){
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = element;
    }
}

int main (){
    int a []= {1,2,3,69,8,5,4,56,100,133};
    int n = sizeof(a)/sizeof(a[0]);
    printf("\n We have the following numbers: ");
    display(a,n);
    printf("\n After sorting the numbers by insertion sort we have :");
    insertion_sort(a,n);
    display(a,n);

}