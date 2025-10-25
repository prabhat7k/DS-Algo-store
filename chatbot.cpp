#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string chatbotResponse(const string& input) {
    static unordered_map<string, string> responses = {
        {"hello", "Hi there! How can I help you today?"},
        {"bye", "Goodbye! Have a great day!"},
        {"hacktoberfest", "That’s awesome! Ready to contribute to open source?"},
        {"thanks", "You're welcome!"}
    };

    string lowered;
    for (char c : input) lowered += tolower(c);

    for (auto& [key, value] : responses)
        if (lowered.find(key) != string::npos) return value;

    return "Sorry, I didn’t understand that.";
}

int main() {
    string input;
    cout << "Chatbot activated (type 'bye' to exit)\n";
    while (true) {
        cout << "> ";
        getline(cin, input);
        string response = chatbotResponse(input);
        cout << response << endl;
        if (input == "bye") break;
    }
}
