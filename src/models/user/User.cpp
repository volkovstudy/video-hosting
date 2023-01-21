#include "User.h"

User::User(int id, const string& name) :
        _id(id),
        _name(name) {}

int User::getId() const {
    return _id;
}

const string& User::getName() const {
    return _name;
}
