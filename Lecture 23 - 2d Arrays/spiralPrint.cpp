#include<iostream>
using namespace std;
#include<bits/stdc++.h>

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int nRows = matrix.size();
        int mCols = matrix[0].size();

        vector<int> ans;

        int count = 0;
        int total = nRows * mCols;

        int startingRow = 0; 
        int startingCol = 0;
        int endingRow = nRows-1; 
        int endingCol = mCols-1;

        while(count < total){
            for(int index = startingCol; count < total && index <= endingCol; index++ ){
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            for(int index = startingRow; count < total && index <= endingRow; index++ ){
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            for(int index = endingCol; count < total && index >= startingCol; index-- ){
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            for(int index = endingRow; count < total && index>=startingRow; index-- ){
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }

int main(){
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<int> result = spiralOrder(matrix);

    cout << "Spiral order traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}