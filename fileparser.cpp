#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ifstream file("sample.txt");
    if (!file.is_open()) {
        cerr << "File not found.\n";
        return 1;
    }

    unordered_map<string, int> wordCount;
    string word;
    while (file >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end());
        wordCount[word]++;
    }

    cout << "Top words:\n";
    for (auto &w : wordCount)
        if (w.second > 1)
            cout << w.first << ": " << w.second << endl;
}
