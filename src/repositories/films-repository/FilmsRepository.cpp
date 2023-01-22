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
