// C++ program to implement Comb Sort
#include <bits/stdc++.h>
using namespace std;

int nextGap(int gap) {
    gap = (gap * 10) / 13; // shrink factor ~1.3
    return max(1, gap);
}

void combSort(int arr[], int n) {
    int gap = n; bool swapped = true;
    while (gap != 1 || swapped) {
        gap = nextGap(gap);
        swapped = false;
        for (int i = 0; i + gap < n; ++i) {
            if (arr[i] > arr[i + gap]) { swap(arr[i], arr[i + gap]); swapped = true; }
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 6, 3, 8, 4, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";

    combSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    return 0;
}
