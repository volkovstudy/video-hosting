#include <cassert>

#include "repositories/users-repository/UsersRepository.h"

#define databaseDelimiter ','
#define testFile "users-repository-test.txt"

void shouldFindAllUsers();

int main() {
    shouldFindAllUsers();
    ::remove(testFile);

    return 0;
}

void writeUsersToFile(vector<User> users, FileService& fileService) {
    for (const User& user: users) {
        stringstream stream;
        stream << user.getId() << databaseDelimiter << user.getName() << databaseDelimiter << "P@ssw0rd";

        fileService.write(stream.str());
    }
}

void shouldFindAllUsers() {
    UsersRepository usersRepository(testFile);

    // Given
    vector<User> users = {User(1, "Petr"), User(2, "Alexander")};
    FileService fileService = FileService(testFile);
    writeUsersToFile(users, fileService);

    vector<User> foundUsers = usersRepository.findAll();

    assert(users == foundUsers);
}
