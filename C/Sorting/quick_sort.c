#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 500000

int partition(int a[], int l, int r){
    int x =l ,y = r, pivot = a[l],temp;
    while(x<y ){
        while(a[x]<= pivot && x<= r){
            x++;
        }
        while(a[y]>pivot && y>= l){
            y--;
        }
        if(x<y){
            temp = a[x];
            a[x] = a[y];
            a[y] = temp;
        }
       
    }
    a[l] = a[y];
    a[y] = pivot;
    return y;
}
void quick_sort(int a[], int l , int r){
    if(l,r){
       int p = partition(a, l , r);
       quick_sort(a , l, p-1);
       quick_sort(a, p+1 , l);
    }
}

void display(int a[],int n ){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);

    }
    printf("\n");
}
int main(){
    int i, a[MAX],n;
    srand(time(NULL));
    time_t t1,t2;
    double d;

    printf("Enter the value of n: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        a[i] = rand();
    }
    printf("The random %d numbers are \n",n);
    // display(a,n);
    t1 = time(NULL);
    quick_sort(a,0 , n-1);
    t2 = time(NULL);
    printf("\nAfter sorting the %d numbers are:\n ",n);
    // display(a,n);
    d = difftime(t2,t1);
    printf("The time is %lf seconds\n",d);
    return 0;
}