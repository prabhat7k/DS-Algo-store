#include <bits/stdc++.h>
using namespace std;

// Rabin-Karp String Matching
void rabinKarp(string text, string pattern, int q = 101) {
    int n = text.size(), m = pattern.size();
    int d = 256; // number of characters
    int h = 1, p = 0, t = 0;

    for (int i = 0; i < m - 1; i++) h = (h * d) % q;
    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t && text.substr(i, m) == pattern)
            cout << "Pattern found at index " << i << endl;
        if (i < n - m)
            t = (d * (t - text[i] * h) + text[i + m]) % q;
        if (t < 0) t += q;
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    rabinKarp(text, pattern);
    return 0;
}
