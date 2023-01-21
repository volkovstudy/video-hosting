#include <cassert>

#include "repositories/users-repository/UsersRepository.h"

#define databaseDelimiter ','
#define testFile "users-repository-test.txt"

void shouldFindAllUsers();
void shouldFindUserById();
void shouldNotFindUserById();

int main() {
    shouldFindAllUsers();
    ::remove(testFile);

    shouldFindUserById();
    ::remove(testFile);

    shouldNotFindUserById();
    ::remove(testFile);

    return 0;
}

vector<User> givenTwoUsersInDatabase() {
    vector<User> users = {User(1, "Petr"), User(2, "Alexander")};

    FileService fileService(testFile);

    for (const User& user: users) {
        stringstream stream;
        stream << user.getId() << databaseDelimiter << user.getName() << databaseDelimiter << "P@ssw0rd";

        fileService.write(stream.str());
    }

    return users;
}

void shouldFindAllUsers() {
    UsersRepository usersRepository(testFile);

    vector<User> users = givenTwoUsersInDatabase();

    vector<User> foundUsers = usersRepository.findAll();

    assert(users == foundUsers);
}

void shouldFindUserById() {
    UsersRepository usersRepository(testFile);

    vector<User> users = givenTwoUsersInDatabase();

    User userOne = usersRepository.findById(1);
    User userTwo = usersRepository.findById(2);

    assert(userOne.getId() == 1 && users.at(0) == userOne);
    assert(userTwo.getId() == 2 && users.at(1) == userTwo);
}

void shouldNotFindUserById() {
    UsersRepository usersRepository(testFile);

    givenTwoUsersInDatabase();

    try {
        usersRepository.findById(9999);
        assert(false == true); // This line shouldn't be run
    } catch (runtime_error& error) {
        // If caught, the test passed
    }
}
