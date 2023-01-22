#include "UsersLineParser.h"

#define databaseDelimiter ','

map<string, string> convertLineToFields(const string& line);

User UsersLineParser::parse(const string& line) {
    map<string, string> fields = UsersLineParser::convertLineToFields(line);

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

map<string, string> UsersLineParser::convertLineToFields(const string& line) {
    map<string, string> fields;
    vector<string> splitLine = Utils::split(line, databaseDelimiter);

    // Line format: id,name,password
    fields["id"] = splitLine.at(0);
    fields["name"] = splitLine.at(1);
    fields["password"] = splitLine.at(2);

    return fields;
}
