#ifndef SODAS_PIPE_ACCESS_H
#define SODAS_PIPE_ACCESS_H

#include <string>

class DevexvsPipeAccess {
private:
    std::string domain;

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output);

public:
    SodasPipeAccess::DevexvsPipeAccess() {
    domain = "example.com";
}

void DevexvsPipeAccess::setDomain(const std::string& domain) {
    this->domain = domain;
}

#endif
