
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> rowWiseSum(vector<vector<int>> arr){
    int n = arr.size();
    int m = arr[0].size();
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int sum = 0;
       for( int j = 0; j <  arr[i].size(); j++){
        sum += arr[i][j];
       }
       ans.push_back(sum);
    
}
return ans;
}

int maxSum(vector<vector<int>> arr){
    
    vector<int> x = rowWiseSum(arr);
    return *max_element(x.begin(), x.end());
}

int main(){
    // int n = 3;
     vector<vector<int>> arr(3, vector<int>(3));

    // int n = arr.size();
    // int m = arr[0].size();
    for(int i = 0; i < 3; i++){
       for( int j = 0; j <3; j++){
        cout << "enter element" << i << endl;
        cout << " enter element" << j << endl;
        cin >> arr[i][j];
        cout << " ";
       }
    }
    cout << maxSum(arr) << endl;
}