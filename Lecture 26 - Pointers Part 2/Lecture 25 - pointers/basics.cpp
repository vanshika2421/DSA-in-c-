#include<iostream>
using namespace std;

int main(){
    int n = 8;

    cout << n << endl;
    cout << &n << endl;

    int *ptr = &n;
    cout << &ptr << endl;
    // * -> prints the value 
    // & -> prints the address
    cout << *ptr << endl;

    cout << sizeof(n) << endl;
    cout << sizeof(ptr) << endl; 
}





