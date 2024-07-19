#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cout << "enter your number here : ";

    cin >> n;
    int answer;
    int i = 0;
    while(n!=0){
        int digit = n & 1;
        answer = (pow(10,i) * digit) + answer;
        n = n >> 1;
        i++;
    }
    cout << answer;
    
}