#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;

    int first[n1], second[n2];

    for(int i = 0;i<n1;i++){
        first[i] = arr[l+i];
    }
     for(int j = 0;j<n2;j++){
        second[j] = arr[m+1+j];
    }

    int i = 0; 
    int j = 0;
    int k =l;
 while (i < n1 && j < n2) {
        if (first[i] <= second[j]) {
            arr[k] = first[i];
            i++;
        } else {
            arr[k] = second[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = first[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = second[j];
        j++;
        k++;
    }

}


void mergeSort(int arr[], int l, int r){
    if(l>r){
        return ; 
    }
    int mid = l+(r-l) /2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);



}










void print(int arr[], int n ){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}


int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);
    print(arr,n);

    // Time complexity: O(n log n)
    // Space complexity: O(n)
    return 0;
}
