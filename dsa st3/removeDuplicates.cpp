#include <iostream>
using namespace std;

void removeDuplicates(int arr[], int& size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size;) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < size - 1; ++k) {
                    arr[k] = arr[k + 1];
                }
                --size;
            } else {
                ++j;
            }
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 5, 3};
    int size = 7;

    removeDuplicates(arr, size);

    // Print the array after removing duplicates
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }

    return 0;
}
