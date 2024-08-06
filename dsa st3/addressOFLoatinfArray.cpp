#include <iostream>
using namespace std;

int main() {
    float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    for (int i = 0; i < 5; ++i) {
        cout << "Address of arr[" << i << "]: " << &arr[i] << endl;
    }
    return 0;
}

