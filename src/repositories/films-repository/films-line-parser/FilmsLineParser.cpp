#include "FilmsLineParser.h"

#define databaseDelimiter ','

vector<string> split(const string& line, char delimiter);
map<string, string> convertLineToFields(const string& line);

Film FilmsLineParser::parse(const string& line) {
    map<string, string> fields = convertLineToFields(line);

    Film film(
            stoi(fields["id"]),
            fields["title"],
            stoi(fields["mark"])
    );

    return film;
}

string FilmsLineParser::parse(const Film& film) {
    stringstream line;

    line << film.getId() << databaseDelimiter;
    line << film.getTitle() << databaseDelimiter;
    line << film.getMark();

    return line.str();
}

vector<string> split(const string& line, char delimiter) {
    vector<string> result;

    stringstream stream(line);
    string item;

    while (getline(stream, item, delimiter)) {
        result.push_back(item);
    }

    return result;
}

map<string, string> convertLineToFields(const string& line) {
    map<string, string> fields;
    vector<string> splitLine = split(line, databaseDelimiter);

    // Line format: id,title,mark
    fields["id"] = splitLine.at(0);
    fields["title"] = splitLine.at(1);
    fields["mark"] = splitLine.at(2);

    return fields;
}
