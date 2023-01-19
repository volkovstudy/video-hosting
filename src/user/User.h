#ifndef VIDEO_HOSTING_USER_H
#define VIDEO_HOSTING_USER_H


#include <string>

using namespace std;

class User {
private:
    int _id;
    string _name;
    string _password;
public:
    int getId() const;
    const string &getName() const;
};


#endif
