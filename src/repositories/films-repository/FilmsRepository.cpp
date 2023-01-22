#include "FilmsRepository.h"

FilmsRepository::FilmsRepository(const string& filePath) : filePath(filePath) {}

vector<Film> FilmsRepository::findAll() {
    if (!cache.empty()) return cache;

    FileService fileService(filePath);

    vector<string> fileContent = fileService.readAll();

    vector<Film> films;

    for (const string& line: fileContent) {
        Film film = FilmsLineParser::parse(line);
        films.push_back(film);
    }

    cache = films;

    return films;
}

Film& FilmsRepository::findById(int id) {
    if (cache.empty()) {
        findAll();

        if (cache.empty()) {
            throw runtime_error("Database is empty");
        }
    }

    for (Film& film: cache) {
        if (film.getId() == id) {
            return film;
        }
    }

    stringstream message;
    message << "Didn't find film with id " << id;

    throw runtime_error(message.str());
}
