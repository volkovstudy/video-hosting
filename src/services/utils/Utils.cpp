#include "Utils.h"

vector<string> Utils::split(const string& line, char delimiter) {
    vector<string> result;

    stringstream stream(line);
    string item;

    while (getline(stream, item, delimiter)) {
        result.push_back(item);
    }

    return result;
}
