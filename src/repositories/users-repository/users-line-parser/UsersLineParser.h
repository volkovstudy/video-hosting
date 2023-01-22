#ifndef VIDEO_HOSTING_USERSLINEPARSER_H
#define VIDEO_HOSTING_USERSLINEPARSER_H


#include "models/user/User.h"
#include "services/utils/Utils.h"

#include <string>
#include <vector>
#include <sstream>
#include <map>

class UsersLineParser {
public:
    static User parse(const string& line);
    static string parse(const User& user, const string& password);
};


#endif
