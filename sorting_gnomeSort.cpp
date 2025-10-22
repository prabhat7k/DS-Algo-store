// C++ program to implement Gnome Sort
#include <bits/stdc++.h>
using namespace std;

void gnomeSort(int arr[], int n) {
    int i = 0;
    while (i < n) {
        if (i == 0 || arr[i] >= arr[i - 1]) ++i;
        else { swap(arr[i], arr[i - 1]); --i; }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 6, 3, 8, 4, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";

    gnomeSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    return 0;
}
