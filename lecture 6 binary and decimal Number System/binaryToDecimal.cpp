#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n ;
    cout << "enter your number here: ";
    cin >> n;
    int i = 0;
    int answer = 0;
    while(n!=0){
        int digit = n%10;;
        if(digit == 1){
            answer = pow(2,i)  + answer;
        }
}
cout << answer << endl;
}