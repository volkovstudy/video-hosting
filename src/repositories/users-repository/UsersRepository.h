#ifndef VIDEO_HOSTING_USERSREPOSITORY_H
#define VIDEO_HOSTING_USERSREPOSITORY_H


#include "../../models/user/User.h"

#include <vector>

class UsersRepository {
public:
    vector<User> findAll();
    User& findById(int id);

    void save(const User& user);
};


#endif
