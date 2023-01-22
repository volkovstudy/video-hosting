#ifndef VIDEO_HOSTING_UTILS_H
#define VIDEO_HOSTING_UTILS_H


#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Utils {
public:
    static vector<string> split(const string& line, char delimiter);
};


#endif
