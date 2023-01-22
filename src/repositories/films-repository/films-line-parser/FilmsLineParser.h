#ifndef VIDEO_HOSTING_FILMSLINEPARSER_H
#define VIDEO_HOSTING_FILMSLINEPARSER_H


#include "models/film/Film.h"
#include "services/utils/Utils.h"

#include <string>
#include <sstream>
#include <map>
#include <vector>

class FilmsLineParser {
private:
    static map<string, string> convertLineToFields(const string& line);
public:
    static Film parse(const string& line);
    static string parse(const Film& film);
};


#endif
