#include<iostream>

using namespace std;

class heap{
    public:
    int arr[1000];
    int size;


    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size++; // 0th index ko avoid krna hai
        int i = size;
        arr[i] = val;

        while(i > 1){
            int parent = i/2;
        if(arr[parent] < arr[i]){ // max heap mai niche wala element bda hona chahiye isliye hi parent < i;
            swap(arr[parent], arr[i]);
            i = parent;
        }
        else{
            return;
        }
        }
    }

    void print(){
        for(int i = 1; i <= size; i++){
             cout << arr[i] << " ";
        }
        cout << endl;
    }
// // manlo val = 9; and size = 8; that is 7 tak eleemnts fill hai to tumne arr[i] which means arr[8] = 9 daaldiya.

void deleteNode(){
    if(size == 0) {
        cout << " nothing to return" << endl;
    }
    arr[1] = arr[size];
    size--;

    int i = 1;
    while(i < size)
{
    int leftindex = 2*i;
    int rightindex = 2*i+1;


    if(leftindex < size && arr[leftindex] > arr[i]){
        swap(arr[leftindex] , arr[i]);
        i = leftindex;
    }
    else if(rightindex < size && arr[rightindex] > arr[i]){
        swap(arr[rightindex] , arr[i]);
        i = rightindex;
    }
    else{
        return;
    }
}
}

void heapifyAlgorithm(int arr[], int size, int i){
    int half = size/2;
    int largest = i;
    int leftIndex =  2*i;
    int rightIndex = 2 * i + 1;

    // for(i = half ; i>=1; i--){
    //     if(arr[i] > arr[leftIndex] && arr[i] > arr[rightIndex] || arr[i] > arr[leftIndex] && arr[i] < arr[rightIndex]){
    //         swap(arr[i], arr[leftIndex]);
    //     }
    //     else if( arr[i] > arr[rightIndex] && arr[i] < arr[leftIndex]){
    //         swap(arr[i], arr[rightIndex]);
    //     }
    //     else{
    //         return;
    //     }
    // }
    if(leftIndex < size && arr[largest] < arr[leftIndex]){
        largest = leftIndex;
    }
    else if(rightIndex < size && arr[largest] < arr[rightIndex]){
        largest = rightIndex;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapifyAlgorithm(arr, size, largest);
    }

}
};

int main(){
    heap h;
    h.insert(90);
    h.insert(10);
    h.insert(11);
    h.insert(42);
    // h.insert(42);
    h.insert(31);
    h.insert(96);
    h.insert(101);
    h.insert(34);
    h.insert(39);
    h.insert(106);
    h.print();
    // h.heapifyAlgorithm(arr,9, 101);
    h.print();
    int arr[6] = {-1,23,45,54,123,53};
    int n = 6;
    for(int i = n/2 ; i>=1; i--){
        // cout << arr[i] <<  " ";
       h.heapifyAlgorithm(arr,n, i);
    }
    cout << " printing array" << " ";
    for(int i = 1; i < n; i++){
        cout << arr[i] <<  " "; 
    }
    cout << endl;

    // h.deleteNode();
    // h.print();
    // h.deleteNode();
    // h.print();
}
