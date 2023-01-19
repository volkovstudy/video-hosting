#ifndef VIDEO_HOSTING_FILM_H
#define VIDEO_HOSTING_FILM_H


#include <string>

using namespace std;

class Film {
private:
    int _id;
    string _title;
    int _mark;
public:
    int getId() const;
    const string &getTitle() const;
    int getMark() const;
};


#endif
