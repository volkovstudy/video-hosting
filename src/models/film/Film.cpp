#include "Film.h"

int Film::getId() const {
    return _id;
}

const string &Film::getTitle() const {
    return _title;
}

int Film::getMark() const {
    return _mark;
}

Film::Film(int id, const string& title, int mark) : _id(id), _title(title), _mark(mark) {}

bool Film::operator==(const Film& rhs) const {
    return _id == rhs._id &&
           _title == rhs._title &&
           _mark == rhs._mark;
}

bool Film::operator!=(const Film& rhs) const {
    return !(rhs == *this);
}
