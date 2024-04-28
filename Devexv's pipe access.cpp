#include "Devexv's pipe access.h"
#include <windows.h>
#include <wininet.h>
#include <iostream>

#pragma comment(lib, "wininet.lib")

SodasPipeAccess::DevexvsPipeAccess() {
    // Initialize domain to a default value or leave it empty
    domain = "example.com";
}

void DevexvsPipeAccess::setDomain(const std::string& domain) {
    this->domain = domain;
}

size_t DevexvsPipeAccess::WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output) {
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

std::string DevexvsPipeAccess::getHTML() {
    HINTERNET hInternet = InternetOpen(L"HTTPGET", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (!hInternet) {
        std::cerr << "Error: InternetOpen failed" << std::endl;
        return "";
    }

    HINTERNET hConnect = InternetOpenUrlA(hInternet, ("https://" + domain).c_str(), NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (!hConnect) {
        std::cerr << "Error: InternetOpenUrl failed" << std::endl;
        InternetCloseHandle(hInternet);
        return "";
    }

    std::string html;
    char buffer[1024];
    DWORD bytesRead;

    while (InternetReadFile(hConnect, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
        html.append(buffer, bytesRead);
    }

    InternetCloseHandle(hConnect);
    InternetCloseHandle(hInternet);

    return html;
}
