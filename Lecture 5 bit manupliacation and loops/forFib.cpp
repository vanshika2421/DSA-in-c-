#include<iostream>
using namespace std;

int main(){
    int n = 10;
    int a = 0; int b = 1;
    for(int i = 0; i <=n; i++){

        int sum = a+b;
        cout << sum << endl; 

        a = b;
        b = sum; 
       
       
}
}