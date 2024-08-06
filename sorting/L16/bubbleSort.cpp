#include<iostream>
using namespace std;

void bubbleSort(int arr[] , int n){
    for(int i = 0; i < n-1; i++){
         for(int j = 0; j < n-1; j++){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
            }
        }
    }
}

int main(){
    int n = 7; 
    int arr[1000] = {1,9,14,7,72,42,43};
    bubbleSort(arr,n);
    for(int i = 0; i < n; i++){
        cout >> arr[i];
    }
}