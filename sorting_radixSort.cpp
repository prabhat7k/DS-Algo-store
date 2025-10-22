// C++ program to implement Radix Sort (LSD, base 10, non-negative)
#include <bits/stdc++.h>
using namespace std;

void countingPass(vector<int>& a, int exp) {
    vector<int> cnt(10, 0), out(a.size());
    for (int v : a) cnt[(v / exp) % 10]++;
    for (int i = 1; i < 10; ++i) cnt[i] += cnt[i - 1];
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        int d = (a[i] / exp) % 10;
        out[--cnt[d]] = a[i];
    }
    a.swap(out);
}

void radixSortNonNeg(int arr[], int n) {
    for (int i = 0; i < n; ++i) if (arr[i] < 0) { cerr << "Only non-negative allowed\n"; return; }
    vector<int> a(arr, arr + n);
    int mx = *max_element(a.begin(), a.end());
    for (int exp = 1; mx / exp > 0; exp *= 10) countingPass(a, exp);
    for (int i = 0; i < n; ++i) arr[i] = a[i];
}

int main() {
    int arr[] = {5, 2, 90, 1, 6, 3, 80, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";

    radixSortNonNeg(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; ++i) cout << arr[i] << " ";
    return 0;
}
