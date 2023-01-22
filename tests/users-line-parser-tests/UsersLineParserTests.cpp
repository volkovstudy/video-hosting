#include <iostream>
#include <cassert>

#include "repositories/users-repository/users-line-parser/UsersLineParser.h"

void shouldParseLineIntoUserInstance();
void shouldParseLineIntoMap();
void shouldParseUserIntoString();

int main() {
    shouldParseLineIntoUserInstance();

    shouldParseUserIntoString();

    shouldParseLineIntoMap();

    return 0;
}

void shouldParseLineIntoUserInstance() {
    User user = UsersLineParser::parse("1,Petr,P@ssw0rd");

    assert(user.getId() == 1);
    assert(user.getName() == "Petr");
}

void shouldParseLineIntoMap() {
    string line = "1,Petr,P@ssw0rd";

    map<string, string> fields = UsersLineParser::parseIntoFields(line);

    assert(fields["id"] == "1");
    assert(fields["name"] == "Petr");
    assert(fields["password"] == "P@ssw0rd");
}

void shouldParseUserIntoString() {
    User user(1, "Petr");
    string password = "P@ssw0rd";

    string parsedLine = UsersLineParser::parse(user, password);

    assert("1,Petr,P@ssw0rd" == parsedLine);
}
