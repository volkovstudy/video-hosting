#include "UsersRepository.h"

#define databaseDelimiter ','

UsersRepository::UsersRepository(const string& filePath) : _filePath(filePath) {}

vector<User> UsersRepository::findAll() {
    if (!_cache.empty()) {
        return _cache;
    }

    FileService fileService(_filePath);

    vector<string> fileContent = fileService.readAll();

    vector<User> users;

    for (const string& line: fileContent) {
        User user = UsersLineParser::parse(line);
        users.push_back(user);
    }

    _cache = users;

    return users;
}

User& UsersRepository::findById(int id) {
    if (_cache.empty()) {
        findAll();

        if (_cache.empty())
            throw runtime_error("No users in database!");
    }

    for (User& user: _cache) {
        if (user.getId() == id) {
            return user;
        }
    }

    stringstream message;
    message << "Didn't find user with id " << id;

    throw runtime_error(message.str());
}

void UsersRepository::save(const User& user, const string& password) {
    string line = UsersLineParser::parse(user, password);

    FileService fileService(_filePath);
    fileService.write(line);

    _cache.push_back(user);
}

string UsersRepository::getPasswordByUserId(int id) {
    FileService fileService(_filePath);

    vector<string> fileContent = fileService.readAll();

    string idString = to_string(id);
    string password;

    for (const string& line: fileContent) {
        map<string, string> fields = UsersLineParser::parseIntoFields(line);

        if (fields["id"] != idString) continue;

        return fields["password"];
    }

    stringstream message;
    message << "Didn't find user with id " << id;

    throw runtime_error(message.str());
}
