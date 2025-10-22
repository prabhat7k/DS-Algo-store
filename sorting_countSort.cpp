// C++ program to implement Counting Sort (supports negatives)
#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int n) {
    if (n == 0) return;
    int mn = *min_element(arr, arr + n);
    int mx = *max_element(arr, arr + n);
    long long range = 1LL * mx - mn + 1;
    if (range > 5e6) { cerr << "Range too large for counting sort\n"; return; }

    vector<int> cnt((size_t)range, 0), out(n);
    for (int i = 0; i < n; ++i) cnt[arr[i] - mn]++;
    for (size_t i = 1; i < cnt.size(); ++i) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) out[--cnt[arr[i] - mn]] = arr[i];
    for (int i = 0; i < n; ++i) arr[i] = out[i];
}

int main() {
    int arr[] = {5, -2, 9, 1, -6, 3, 8, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";

    countingSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    return 0;
}
