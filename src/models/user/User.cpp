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

bool User::operator==(const User& rhs) const {
    return _id == rhs._id &&
           _name == rhs._name;
}

bool User::operator!=(const User& rhs) const {
    return !(rhs == *this);
}
