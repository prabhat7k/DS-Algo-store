#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, long long> memo;

long long fibonacci(int n) {
    if (n < 2) return n;
    if (memo.count(n)) return memo[n];
    return memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    for (int i = 0; i < 15; ++i)
        cout << fibonacci(i) << " ";
    cout << endl;
    return 0;
}
