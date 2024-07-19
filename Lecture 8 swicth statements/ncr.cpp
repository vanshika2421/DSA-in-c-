#include<iostream>
using namespace std;

int factorial(int n){
    int fact = 1;
    for(int i = 0; i <=n; i++){
        fact = fact * i;
    }
}

int ncr(int n, int r){
    int nom = factorial(n);
    int denom = factorial(r) * factorial(n-r);
    int ncrr = nom/denom;
    return ncrr;
}

int main(){
    int n;
    int r;
    int x = ncr(5,2);
    cout << x << endl;
}