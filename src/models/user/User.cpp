#include "User.h"

User::User(int id, const string& name, const string& password) :
        _id(id),
        _name(name),
        _password(password) {}

int User::getId() const {
    return _id;
}

const string& User::getName() const {
    return _name;
}
