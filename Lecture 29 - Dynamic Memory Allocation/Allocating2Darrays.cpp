#include<iostream>
using namespace std;
int main(){
    cout << "give number of matrices rows and cols :" ;
int n;
cin >> n;
int **arr = new int*[n];
// if rows and cols are diffrent
// int **arr = new int[rows];


for(int i = 0; i < n ; i++){
    arr[i] = new int[n];
}
cout << "taking input" << endl;
for(int i = 0; i < n ; i++){
   for(int j = 0; j< n ; j++){
    cin >> arr[i][j];
   }
}
cout << endl;

cout << "giving output"  << endl;
for(int i = 0; i < n ; i++){
   for(int j = 0; j < n ; j++){
    cout << arr[i][j] << " ";
   }
   cout << endl;
}

for(int i = 0; i <n; i++){
    delete [] arr[i]; // del cols
}
delete []arr; // del rows
}
