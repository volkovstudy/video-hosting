#ifndef VIDEO_HOSTING_FILMSREPOSITORY_H
#define VIDEO_HOSTING_FILMSREPOSITORY_H


#include "../../models/film/Film.h"

#include <vector>

class FilmsRepository {
public:
    vector<Film> findAll();
    Film& findById(int id);
};


#endif
