#include <iostream>
using namespace std;

double findMedian(int arr[], int size) {
    if (size % 2 == 0) {
        // If the size is even, average the middle two elements
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        // If the size is odd, return the middle element
        return arr[size / 2];
    }
}

int main() {
    int arr[] = {1, 2, 3,7,5,4,4, 4, 5};
    int size = 10;

    double median = findMedian(arr, size);

    cout << "Median: " << median << endl;

    return 0;
}
