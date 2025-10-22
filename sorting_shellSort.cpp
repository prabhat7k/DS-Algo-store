// C++ program to implement Shell Sort (Knuth gaps)
#include <bits/stdc++.h>
using namespace std;

void shellSort(int arr[], int n) {
    vector<int> gaps;
    for (int h = 1; h < n; h = 3*h + 1) gaps.push_back(h);
    for (int g = (int)gaps.size() - 1; g >= 0; --g) {
        int gap = gaps[g];
        for (int i = gap; i < n; ++i) {
            int temp = arr[i], j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap]; j -= gap;
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 6, 3, 8, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";

    shellSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    return 0;
}
