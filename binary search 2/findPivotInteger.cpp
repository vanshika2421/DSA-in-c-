#include<iostream>
using namespace std;

int pivotInteger(int arr[], int n){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    while(start <= end){

        mid = start + (end-start)/2; // updated mid else it will give Time Limit Exceed 

        if(arr[mid] >= arr[0]){
            start = mid +1;
        }
        else{
            end = mid;
        }
    }
    return start;
}