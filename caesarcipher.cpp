#include <iostream>
using namespace std;

string encrypt(const string& text, int key) {
    string result;
    for (char c : text) {
        if (isupper(c))
            result += char((c - 'A' + key) % 26 + 'A');
        else if (islower(c))
            result += char((c - 'a' + key) % 26 + 'a');
        else
            result += c;
    }
    return result;
}

string decrypt(const string& text, int key) {
    return encrypt(text, 26 - key);
}

int main() {
    string text = "HacktoberFest";
    int key = 5;
    string enc = encrypt(text, key);
    cout << "Encrypted: " << enc << endl;
    cout << "Decrypted: " << decrypt(enc, key) << endl;
}
