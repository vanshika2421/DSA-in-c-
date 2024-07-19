#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool linearSearch(int arr[][3], int n , int key){
    for(int i = 0; i < n; i++){
       for( int j = 0; j <n; j++){
        if(arr[i][j]== key){
            return true;
        }
       }
       
}
return false;
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
    int key;
    cout << " wht is key t find?: ";
    cin >> key;
    
    
    if(linearSearch(arr,n,key)){
        cout << "key is present";
    }
    else{
        cout << "key is absent";
    }    
}