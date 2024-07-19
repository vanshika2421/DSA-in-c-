#include<iostream>
using namespace std;

int getProduct(int* arr, int n){
    int p = 1;
    for(int i = 1; i < n; i++){
        p *= arr[i];
    }
    return p;
}


int main(){
    int n;
    cin >> n;

    int *arr= new int[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = getProduct(arr,n);
    cout << ans << endl;

//KAAFI KHTNAAK CHIZ AI YAI
// DONT USE THIS
//   while(true){
//         cout << "XXXXXXXXXXXXXX";
//         int i = 5;
//     }

//     while(true){
//         cout << "YYYYYYYYYYYYYYYYYYYYY";
//         int *ch = new int;
//     }

}