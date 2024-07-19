#include<iostream>
#include<vector>
using namespace std;

vector<int> waveprint(vector<vector<int>> matrix){
        int nRows = matrix.size();
        int mCols = matrix[0].size();
        vector<int> ans;
        for(int col = 0; col <mCols; col++){
            if(col & 1){
                for(int row = nRows -1; row>=0; row--){
                    ans.push_back(matrix[row][col]);
                }
            }
            else{
                for(int row = 0; row <nRows; row++){
                    ans.push_back(matrix[row][col]);
                }
            }
        }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<int> result = waveprint(matrix);

    cout << "wave order traversal: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}