#include<iostream>
using namespace std;

int swapAlternate(int arr[], int n){
     
}

void printArray(int arr[], int n){
    for(int i = 0; i <= n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n = 7;
    int arr[1000] = {1,2,3,4,5,6,7,8};
    printArray(arr,7);
    swapAlternate(arr, 7);
    printArray(arr,7);
}