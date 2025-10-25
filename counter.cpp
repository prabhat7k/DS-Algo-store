#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countLines(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file!\n";
        return -1;
    }
    int count = 0;
    string line;
    while (getline(file, line)) count++;
    return count;
}

int main() {
    string filename = "sample.txt";
    int lines = countLines(filename);
    if (lines >= 0)
        cout << "File '" << filename << "' has " << lines << " lines.\n";
}
