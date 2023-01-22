#ifndef VIDEO_HOSTING_FILMSREPOSITORY_H
#define VIDEO_HOSTING_FILMSREPOSITORY_H


#include "models/film/Film.h"
#include "services/file-service/FileService.h"

#include <vector>

class FilmsRepository {
private:
    string filePath;
    vector<Film> cache;
public:
    explicit FilmsRepository(const string& filePath);

    vector<Film> findAll();
    Film& findById(int id);

    void save(Film& film);
};


#endif
