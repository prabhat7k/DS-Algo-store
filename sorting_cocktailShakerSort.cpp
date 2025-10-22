// C++ program to implement Cocktail Shaker Sort
#include <bits/stdc++.h>
using namespace std;

void cocktailShakerSort(int arr[], int n) {
    bool swapped = true;
    int start = 0, end = n - 1;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) { swap(arr[i], arr[i + 1]); swapped = true; }
        }
        if (!swapped) break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) { swap(arr[i], arr[i + 1]); swapped = true; }
        }
        ++start;
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 6, 3, 8, 4, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";

    cocktailShakerSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    return 0;
}
