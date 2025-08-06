#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 200000

void selectionsort(int n , int a[]){
    int i , j, temp,least,pos;
    for(i=0; i<n;i ++){
        pos = i ;
          least = a[i];
        for(j=i+1; j<n; j++){
          
            if(a[j]<least){
                least = a[j];
                pos = j;
                
            }
        }
        if(i!= pos){
            temp = a[i];
            a[i]= a[pos];
            a[pos] = temp;

        }
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
    display(a,n);
    t1 = time(NULL);
    selectionsort(n,a);
    t2 = time(NULL);
    printf("\nAfter sorting the %d numbers are:\n ",n);
    display(a,n);
    d = difftime(t2,t1);
    printf("The time is %lf seconds\n",d);
    return 0;
}