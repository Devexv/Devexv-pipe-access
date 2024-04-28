#ifndef SODAS_PIPE_ACCESS_H
#define SODAS_PIPE_ACCESS_H

#include <string>

class DevexvsPipeAccess {
private:
    std::string domain;

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *output);

public:
    SodasPipeAccess();
    std::string getHTML();
    void setDomain(const std::string& /*your domain here*/);
};

#endif
