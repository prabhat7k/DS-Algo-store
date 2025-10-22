#include <iostream>
#include <regex>
using namespace std;

string checkPasswordStrength(const string& password) {
    bool length = password.size() >= 8;
    bool upper = regex_search(password, regex("[A-Z]"));
    bool lower = regex_search(password, regex("[a-z]"));
    bool digit = regex_search(password, regex("\\d"));
    bool special = regex_search(password, regex("[@$!%*?&]"));

    int score = length + upper + lower + digit + special;

    if (score == 5) return "Strong";
    if (score >= 3) return "Moderate";
    return "Weak";
}

int main() {
    string password;
    cout << "Enter password: ";
    cin >> password;
    cout << "Password strength: " << checkPasswordStrength(password) << endl;
    return 0;
}
