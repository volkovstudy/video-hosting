#include "UsersRepository.h"

UsersRepository::UsersRepository(const string& filePath) : filePath(filePath) {}

vector<User> UsersRepository::findAll() {
    FileService fileService(filePath);

    vector<string> fileContent = fileService.readAll();

    vector<User> users;

    for (const string& line: fileContent) {
        User user = UsersLineParser::parse(line);
        users.push_back(user);
    }

    return users;
}
