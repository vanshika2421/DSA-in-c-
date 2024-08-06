#include<iostream>
using namespace std;

int partition(int arr[],int s, int e){
    int pivot = arr[s];
    int count  = 0;
    for(int i = s+1; i < e;i++){
        if(arr[i] < pivot){
            count++;
        }
    }
    int pivotIndex = s+count;
    swap(arr[pivotIndex], arr[s]);

    int i = s;
    int j = e;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
    }

void quickSort(int arr[], int s, int e){

    // int mid = (s+e)/2;
    //base case
    if(s>=e){
        return ;
    }
    int p = partition(arr,s,e);
    quickSort(arr,p+1,e);
    quickSort(arr,s,p-1);

}

void print(int arr[], int n ){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}


int main(){
    int arr[] = {6,7,1,2,3,9,8,65,43,87,63,9999};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);
    print(arr,n);

    // Time complexity: O(n log n) in average case
    // Space complexity: O(log n)

    return 0;
}
