#ifndef PINGBACK_H
#define PINGBACK_H

#include <map>
#include <curl/curl.h>
#include <cstring>


class Pingback
{
    public:
        Pingback(char url[]);
        void setParameter(char parameter, char value[]);
        void send();
        void setIdentifier(char *str);
        virtual ~Pingback();
    protected:
    private:
        char *identifier;
        std::map<char, char*> *parameters_map;
        char *baseURL;
        CURL *curl;
};

#endif // PINGBACK_H
