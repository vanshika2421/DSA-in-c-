#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<vector<int>> linearSearch(vector<vector<int>> arr){
    int n = arr.size();
    int m = arr[0].size();
    // int m = arr[0].size();
    for(int i = 0; i < n; i++){
       for( int j = 0; j <m; j++){
        swap(arr[i][j], arr[j][i]);
       }
    }
    for(int i = 0; i < n ; i++){
        reverse(arr[i].begin(), arr[i].end());
    }
    return arr;
}

int main(){
    // int m = arr[0].size();
    int n,m;
    cout << " give n and m";
    cin >> n >> m; 
     vector<vector<int>> arr(n, vector<int>(m));

    for(int i = 0; i < n; i++){
       for( int j = 0; j <m; j++){
        cout << "enter element" << i << endl;
        cout << " enter element" << j << endl;
        cin >> arr[i][j];
        cout << " ";
       }
    }

    vector<vector<int>> rotate = linearSearch(arr);

    for(int i = 0; i < rotate.size(); i++){
       for( int j = 0; j < rotate[0].size(); j++){
        cout << rotate[i][j] << " "; 
       }
    }
}