#define CURL_STATICLIB

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <pcap.h>
#pragma comment (lib, "libcurl.lib")
#pragma comment (lib, "Normaliz.lib")
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Wldap32.lib")
#pragma comment (lib, "Crypt32.lib")
int main() {
    CURL* curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        std::string serverIP;
        std::string message;
        // Prompt user for server IP
        std::cout << "what is the server you want to connect to?:";
        std::cin >> serverIP;
        while (true) {

            // Prompt user for message input
            std::cout << "Enter your message: ";
            std::cin.ignore(); // Clear input buffer
            std::getline(std::cin, message);

            std::string url = "http://" + serverIP;
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, message.c_str());

            res = curl_easy_perform(curl);
            std::string choice;
            std::cout << "Do you want to send another message? (yes/no): ";
            std::cin >> choice;
            if (choice != "yes")
                break;
        }

        
        curl_easy_cleanup(curl);
    }

    return 0;
}