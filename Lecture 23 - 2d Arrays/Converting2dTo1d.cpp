#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main(){
    int n = 3;
    int arr[3][3];
    int ans[n*n];
    //input
    int col = 3;
    for(int i = 0; i < n; i++){
       for( int j = 0; j <n; j++){
        int x = col * i + j;
        ans[x];
    } 
    //output
    for(int i = 0; i < n; i++){
       for( int j = 0; j <n; j++){
        cout << arr[i][j] << " ";
        // cout << " ";
       }
    }
}
}