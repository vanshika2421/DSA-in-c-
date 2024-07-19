#include<bits/stdc++.h>
using namespace std;

void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i = 0; i < n/2; i++){
            // for(int j = n-1; j>=i; j--){
            //     swap(s[i] , s[j]);
            // }
            swap(s[i], s[n-i-1]);
        }
    }


int main(){
    int n = 5;
    vector<char> name = {'h', 'e','l', 'l', 'o'};
   reverseString(name);
   for(char c: name){
    cout << c;
   }
   
}