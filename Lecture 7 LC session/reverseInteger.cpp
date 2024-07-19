#include<iostream>
using namespace std;

int reverseInteger(int n){
    int ans = 0;
    while(n!= 0){
        int digit = n%10;
        ans = (ans*10)+ digit;
        n = n >> 1;
    }
    return ans;    
}
int main(){

    int n;
    cin >> n;
    int x = reverseInteger(n);
    cout << x << endl;
}