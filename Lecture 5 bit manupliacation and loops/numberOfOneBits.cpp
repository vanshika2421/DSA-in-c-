#include<iostream>
using namespace std;
int main(){
    int n ;
    cout << "enter the number: ";
    cin >> n;
    int count = 0;

    while(n!=0){
        int digit = n%10;
        if(digit == 1){
            count++;
        }
        n = n / 10;
    }
    cout << count << endl;
}