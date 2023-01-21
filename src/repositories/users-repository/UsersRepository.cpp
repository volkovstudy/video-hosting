#include "UsersRepository.h"

vector<User> UsersRepository::findAll() {
    FileService fileService(usersFile);

    vector<string> fileContent = fileService.readAll();

    vector<User> users;

    for (const string& line: fileContent) {
        User user = UsersLineParser::parse(line);
        users.push_back(user);
    }

    return users;
}
