#include "UsersLineParser.h"

#define databaseDelimiter ','

vector<string> split(const string& line, char delimiter);
map<string, string> convertLineToFields(const string& line);

User UsersLineParser::parse(const string& line) {
    map<string, string> fields = convertLineToFields(line);

    User user(
            stoi(fields["id"]),
            fields["name"]
    );

    return user;
}

string UsersLineParser::parse(const User& user, const string& password) {
    stringstream line;

    line << user.getId() << databaseDelimiter;
    line << user.getName() << databaseDelimiter;
    line << password;

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

    // Line format: id,name,password
    fields["id"] = splitLine.at(0);
    fields["name"] = splitLine.at(1);
    fields["password"] = splitLine.at(2);

    return fields;
}
