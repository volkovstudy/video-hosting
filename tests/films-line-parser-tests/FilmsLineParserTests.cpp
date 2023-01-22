#include <iostream>
#include <cassert>

#include "repositories/films-repository/films-line-parser/FilmsLineParser.h"

void shouldParseLineIntoFilmInstance();
void shouldParseFilmIntoString();

int main() {
    shouldParseLineIntoFilmInstance();

    shouldParseFilmIntoString();

    return 0;
}

void shouldParseLineIntoFilmInstance() {
    Film film = FilmsLineParser::parse("1,The Fast and The Furious,99");

    assert(film.getId() == 1);
    assert(film.getTitle() == "The Fast and The Furious");
    assert(film.getMark() == 99);
}

void shouldParseFilmIntoString() {
    Film film(1, "The Fast and The Furious", 99);

    string parsedLine = FilmsLineParser::parse(film);

    assert("1,The Fast and The Furious,99" == parsedLine);
}
