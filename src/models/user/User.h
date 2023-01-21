#ifndef VIDEO_HOSTING_USER_H
#define VIDEO_HOSTING_USER_H


#include <string>

using namespace std;

class User {
private:
    int _id;
    string _name;
public:
    User(int id, const string& name);

    int getId() const;
    const string &getName() const;

    bool operator==(const User& rhs) const;
    bool operator!=(const User& rhs) const;
};


#endif
