#include "UsersRepository.h"

UsersRepository::UsersRepository(const string& filePath) : filePath(filePath) {}

vector<User> UsersRepository::findAll() {
    if (!cache.empty()) {
        return cache;
    }

    FileService fileService(filePath);

    vector<string> fileContent = fileService.readAll();

    vector<User> users;

    for (const string& line: fileContent) {
        User user = UsersLineParser::parse(line);
        users.push_back(user);
    }

    cache = users;

    return users;
}

User& UsersRepository::findById(int id) {
    if (cache.empty()) {
        findAll();

        if (cache.empty())
            throw runtime_error("No users in database!");
    }

    for (User& user: cache) {
        if (user.getId() == id) {
            return user;
        }
    }

    stringstream message;
    message << "Didn't find user with id " << id;

    throw runtime_error(message.str());
}
