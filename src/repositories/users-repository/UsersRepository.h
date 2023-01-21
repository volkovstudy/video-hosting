#ifndef VIDEO_HOSTING_USERSREPOSITORY_H
#define VIDEO_HOSTING_USERSREPOSITORY_H


#include "models/user/User.h"

#include "services/file-service/FileService.h"
#include "repositories/users-repository/users-line-parser/UsersLineParser.h"

#include <vector>

class UsersRepository {
private:
    string filePath;

    vector<User> cache;
public:
    explicit UsersRepository(const string& filePath);

    vector<User> findAll();
    User& findById(int id);

    void save(const User& user, const string& password);
};


#endif
