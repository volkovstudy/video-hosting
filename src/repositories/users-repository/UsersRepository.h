#ifndef VIDEO_HOSTING_USERSREPOSITORY_H
#define VIDEO_HOSTING_USERSREPOSITORY_H


#include "../../models/user/User.h"

class UsersRepository {
public:
    User& findById(int id);
};


#endif
