#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;
    
    void insert(int value){
        size++; // cause 0 index ko involve nahi krna.
        int i = size;
        arr[i] = value;

        while(i > 1){
            int parent = i/2;
            if(arr[i] > arr[parent]){
                swap(arr[i] , arr[parent]);
                i = parent;
      }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i = 0 ; i < size; i++){
            cout << arr[i] << endl;
        }
        cout << endl;
    }

    void deletefromHeap(){
        if(size == 0){
            cout << " nothing to delete from heap" << endl;
        }
        arr[1] = arr[size];
        size--;
        
        int i = 1;
        while( i < size){
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }
};


int main(){
    heap h;
    h.insert(100);
    h.insert(50);
    h.insert(90);
    h.insert(20);
    h.insert(110);
    h.insert(10);
    h.print();
}