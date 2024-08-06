#include<iostream>
using namespace std;

int bookAllocate(vector<int> &arr, int m){
    //n = number of books
    // m = no. of students
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2; 
    int ans = -1;
    if(isPossible(arr, n, m, mid)){
        ans = mid;
        e = mid -1;
    }
    else{
        s = mid -1;
    }
    return ans;
}


bool isPossible(vector<int> arr, int n, int m, int mid) {
    int studentCount = 0;
    int pagesSum= 0;
    for(int i = 0; i < n; i++){
        if(pagesSum > arr[i]){
            pagesSum += arr[i];
        }
        else{
            if(studentCount > m || arr[i] > mid){
                return false;
            }
            pages = arr[i];
        }
        
    }
    return true;
}