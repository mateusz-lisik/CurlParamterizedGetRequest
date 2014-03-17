#include "Pingback.h"

Pingback::Pingback(char url[])
{
    identifier = NULL;
    baseURL = new char[255];
    baseURL = url;
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, 0);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, 0);
    parameters_map = new std::map<char, char*>;

}

Pingback::~Pingback()
{
    curl_easy_cleanup(curl);
}

void Pingback::setParameter(char parameter, char *value)
{
    parameters_map->insert(std::pair<char, char*>(parameter, value));
}

void Pingback::send()
{
    char *combinedURL = new char[255];
    char *actionSymbol = new char[2];
    actionSymbol[1] = '\0';

    strcpy(combinedURL, baseURL);
    strcat(combinedURL, "?");

    std::map<char, char*>::iterator it = parameters_map->begin();

    for (; it != parameters_map->end(); ++it) {
        if (it != parameters_map->begin()) {
            strcat(combinedURL, "&");
        }

        actionSymbol[0] = it->first;

        strcat(combinedURL, actionSymbol);
        strcat(combinedURL, "=");
        strcat(combinedURL, (char *)it->second);
    }

    if (identifier != NULL) {
        if (parameters_map->size() > 0) {
            strcat(combinedURL, "&");
        }
            strcat(combinedURL, "id=");
            strcat(combinedURL, identifier);
    }

    curl_easy_setopt(curl, CURLOPT_URL, combinedURL);
    curl_easy_perform(curl);
}

void Pingback::setIdentifier(char *str) {
    identifier = str;
}
