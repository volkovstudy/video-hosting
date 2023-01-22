#include <cassert>

#include "repositories/films-repository/FilmsRepository.h"

#define testFile "films-repository-test.txt"
#define databaseDelimiter ','

void shouldFindAllFilms();
void shouldFindFilmById();

int main() {
    shouldFindAllFilms();
    ::remove(testFile);

    shouldFindFilmById();
    ::remove(testFile);

    return 0;
}

vector<Film> givenTwoFilmsInDatabase() {
    vector<Film> films = {
            Film(1, "The Fast and The Furious", 99),
            Film(2, "Cheburashka", 50)
    };

    FileService fileService(testFile);

    for (const Film& film: films) {
        stringstream line;
        line << film.getId() << databaseDelimiter << film.getTitle() << databaseDelimiter << film.getMark();

        fileService.write(line.str());
    }

    return films;
}

void shouldFindAllFilms() {
    vector<Film> givenFilms = givenTwoFilmsInDatabase();

    FilmsRepository filmsRepository(testFile);

    vector<Film> foundFilms = filmsRepository.findAll();

    assert(givenFilms == foundFilms);
}

void shouldFindFilmById() {
    vector<Film> givenFilms = givenTwoFilmsInDatabase();

    FilmsRepository filmsRepository(testFile);

    Film filmOne = filmsRepository.findById(1);
    Film filmTwo = filmsRepository.findById(2);

    assert(filmOne == givenFilms.at(0));
    assert(filmTwo == givenFilms.at(1));
}
