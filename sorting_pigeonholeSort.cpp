// C++ program to implement Pigeonhole Sort
#include <bits/stdc++.h>
using namespace std;

void pigeonholeSort(int arr[], int n) {
    if (n == 0) return;
    int mn = *min_element(arr, arr + n);
    int mx = *max_element(arr, arr + n);
    long long range = 1LL * mx - mn + 1;
    if (range > 5e6) { cerr << "Range too large for pigeonhole sort\n"; return; }

    vector<vector<int>> holes((size_t)range);
    for (int i = 0; i < n; ++i) holes[(size_t)(arr[i] - mn)].push_back(arr[i]);

    int idx = 0;
    for (auto &bucket : holes)
        for (int v : bucket) arr[idx++] = v;
}

int main() {
    int arr[] = {8, 3, 3, 2, 7, 6, 9, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";

    pigeonholeSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    return 0;
}
