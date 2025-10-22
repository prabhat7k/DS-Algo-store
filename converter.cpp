#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <nlohmann/json.hpp>  // Install with: sudo apt install nlohmann-json3-dev
using namespace std;
using json = nlohmann::json;

void csvToJson(const string& csvFile, const string& jsonFile) {
    ifstream file(csvFile);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    string line;
    vector<string> headers;
    json jsonData = json::array();

    if (getline(file, line)) {
        stringstream ss(line);
        string header;
        while (getline(ss, header, ',')) headers.push_back(header);
    }

    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        json row;
        int i = 0;
        while (getline(ss, value, ',')) {
            row[headers[i++]] = value;
        }
        jsonData.push_back(row);
    }

    ofstream out(jsonFile);
    out << jsonData.dump(4);
    cout << "✅ Conversion complete!" << endl;
}

int main() {
    csvToJson("data.csv", "data.json");
    return 0;
}
