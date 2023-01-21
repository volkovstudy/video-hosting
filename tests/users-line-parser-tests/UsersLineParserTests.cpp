#include <iostream>
#include <cassert>

#include "repositories/users-repository/users-line-parser/UsersLineParser.h"

void shouldParseLineIntoUserInstance();

int main() {
    shouldParseLineIntoUserInstance();

    return 0;
}

void shouldParseLineIntoUserInstance() {
    User user = UsersLineParser::parse("1,Petr,P@ssw0rd");

    assert(user.getId() == 1);
    assert(user.getName() == "Petr");
}
