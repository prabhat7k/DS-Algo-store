#include <iostream>
#include <thread>
#include <curl/curl.h>
#include <fstream>
#include <vector>
using namespace std;

size_t writeData(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return fwrite(ptr, size, nmemb, stream);
}

void downloadFile(const string& url, const string& filename) {
    CURL* curl = curl_easy_init();
    if (curl) {
        FILE* fp = fopen(filename.c_str(), "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        CURLcode res = curl_easy_perform(curl);
        if (res == CURLE_OK)
            cout << "✅ Downloaded: " << filename << endl;
        else
            cerr << "❌ Failed: " << filename << endl;
        fclose(fp);
        curl_easy_cleanup(curl);
    }
}

int main() {
    vector<pair<string, string>> files = {
        {"https://www.example.com/img1.jpg", "img1.jpg"},
        {"https://www.example.com/img2.jpg", "img2.jpg"}
    };

    vector<thread> threads;
    for (auto& f : files)
        threads.emplace_back(downloadFile, f.first, f.second);
    for (auto& t : threads) t.join();
}
