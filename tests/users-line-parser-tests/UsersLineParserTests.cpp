#include <iostream>
#include <cassert>

#include "repositories/users-repository/users-line-parser/UsersLineParser.h"

void shouldParseLineIntoUserInstance();
void shouldParseUserIntoString();

int main() {
    shouldParseLineIntoUserInstance();

    shouldParseUserIntoString();

    return 0;
}

void shouldParseLineIntoUserInstance() {
    User user = UsersLineParser::parse("1,Petr,P@ssw0rd");

    assert(user.getId() == 1);
    assert(user.getName() == "Petr");
}

void shouldParseUserIntoString() {
    User user(1, "Petr");
    string password = "P@ssw0rd";

    string parsedLine = UsersLineParser::parse(user, password);

    assert("1,Petr,P@ssw0rd" == parsedLine);
}
