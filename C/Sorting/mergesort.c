#include<stdio.h>
#include<stdlib.h>

void Merge(int a[], int l, int m, int r){
    int i = l;
    int j = m+1;
    int k = l;

    int size = r - l + 1;
    int* b = (int*)malloc(size * sizeof(int));
    if (b == NULL) {
        return;
    }

    while(i <= m && j <= r){
        if(a[i] < a[j]){
            b[k - l] = a[i++];
        } else {
            b[k - l] = a[j++];
        }
        k++;
    }

    for(; i<=m; i++, k++){
        b[k - l] = a[i];
    }
    for(; j<=r; j++, k++){
        b[k - l] = a[j];
    }
    for(i=l; i<=r; i++){
        a[i] = b[i - l];
    }
    free(b);
}

void MergeSort(int a[], int l, int r){
    if(l<r) {
        int mid = (l+r)/2;
        MergeSort(a, l, mid);
        MergeSort(a, mid+1, r);
        Merge(a, l, mid, r);
    }
}

void printArray(int a[], int size){
    for (int i=0; i<size; i++){
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main(){
    int a []= {1,2,3,69,8,5,4,56,100,133};
    int n = sizeof(a)/sizeof(a[0]);
    printArray(a, n);
    MergeSort(a, 0, n-1);
    printArray(a, n);
    return 0;
}
