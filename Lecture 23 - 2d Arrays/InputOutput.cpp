#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int n = 3;
    int arr[3][3];
    //input
    for(int i = 0; i < n; i++){
       for( int j = 0; j <n; j++){
        cin >> arr[i][j];
        cout << " ";
       }
    }
    //output
    for(int i = 0; i < n; i++){
       for( int j = 0; j <n; j++){
        cout << arr[i][j] << " ";
        // cout << " ";
       }
    }
    
}