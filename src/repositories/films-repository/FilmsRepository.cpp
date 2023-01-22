#include "FilmsRepository.h"

FilmsRepository::FilmsRepository(const string& filePath) : _filePath(filePath) {}

vector<Film> FilmsRepository::findAll() {
    if (!_cache.empty()) return _cache;

    FileService fileService(_filePath);

    vector<string> fileContent = fileService.readAll();

    vector<Film> films;

    for (const string& line: fileContent) {
        Film film = FilmsLineParser::parse(line);
        films.push_back(film);
    }

    _cache = films;

    return films;
}

Film& FilmsRepository::findById(int id) {
    if (_cache.empty()) {
        findAll();

        if (_cache.empty()) {
            throw runtime_error("Database is empty");
        }
    }

    for (Film& film: _cache) {
        if (film.getId() == id) {
            return film;
        }
    }

    stringstream message;
    message << "Didn't find film with id " << id;

    throw runtime_error(message.str());
}

void FilmsRepository::save(Film& film) {
    string line = FilmsLineParser::parse(film);

    FileService fileService(_filePath);
    fileService.write(line);

    _cache.push_back(film);
}
