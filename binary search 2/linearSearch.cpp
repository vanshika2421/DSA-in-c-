#include<iostream>
using namespace std;
int linearSearch(int arr[] , int n, int key){
    int start = 0; 
    int end = n-1;
    while(start <= end){
        int mid = start + (end-start) /2;
        if(mid == key){
            return mid;
        }
        else if(key > arr[start]){
            start = mid + 1;
        }
        else if(key < arr[end]){
            end = mid - 1;
        }
    }
}


int main(){

}