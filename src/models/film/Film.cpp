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
