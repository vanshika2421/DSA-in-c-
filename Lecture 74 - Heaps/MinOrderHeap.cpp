#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    void insert(int val){
        size++;
        int i = size;
        arr[i] = val;
    


    while(i > 1){
        int parent = i/2;
        if(arr[i] < arr[parent]){
            swap(arr[i], arr[parent]);
            parent = i;
        }
        else{
            return;
        }
    }
    }
    void print(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << endl;
        }
        cout << endl;
    }
};

int main(){
    heap h;
    // heap h;
    h.insert(100);
    h.insert(50);
    h.insert(90);
    h.insert(20);
    h.insert(110);
    h.insert(10); 
    h.print();
}