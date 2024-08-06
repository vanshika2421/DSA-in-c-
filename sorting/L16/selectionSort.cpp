#include<iostream>
using namespace std;

void selectionSort(int arr[], int n){
    
    for(int i = 0; i < n-2; i++){
        int min = i;
        for (int j = 0; j<n; j++){
            if(arr[j] > arr[min]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
}