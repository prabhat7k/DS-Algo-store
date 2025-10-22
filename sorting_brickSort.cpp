// C++ program to implement Odd–Even Sort (Brick Sort)
#include <bits/stdc++.h>
using namespace std;

void oddEvenSort(int arr[], int n) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i <= n - 2; i += 2)
            if (arr[i] > arr[i + 1]) { swap(arr[i], arr[i + 1]); sorted = false; }
        for (int i = 0; i <= n - 2; i += 2)
            if (arr[i] > arr[i + 1]) { swap(arr[i], arr[i + 1]); sorted = false; }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 6, 3, 8, 4, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";

    oddEvenSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    return 0;
}
