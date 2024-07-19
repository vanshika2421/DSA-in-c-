
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void rowWiseSum(int arr[][3], int n){
    
    for(int i = 0; i < n; i++){
        int sum = 0;
       for( int j = 0; j <n; j++){
        sum += arr[i][j];
       }
       cout << sum << endl;
    //    sum = 0;
}
// return sum;
}

int main(){
    int n = 3;
    int arr[3][3];
    for(int i = 0; i < n; i++){
       for( int j = 0; j <n; j++){
        cout << "enter element" << i << endl;
        cout << " enter element" << j << endl;
        cin >> arr[i][j];
        cout << " ";
       }
    }
   rowWiseSum(arr,n);
    // cout << x << endl;
}