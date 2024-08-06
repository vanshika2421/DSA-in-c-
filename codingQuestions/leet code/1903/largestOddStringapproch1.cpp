//MEMORY LIMITS EXCEEDED HERE
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        // vector<string> substring;
        int l = num.length();
        string largestOdd;
        for(int i = 0; i < l; i++){
            for(int j = i; j < l; j++){
                string substring = (num.substr(i,j-i+1));
                if((substring.back() - '0') % 2 != 0 && substring.length() > largestOdd.length()){
                    largestOdd = substring;
                }
            }
        }
        return largestOdd.empty() ? "" : largestOdd;
        
    }
};