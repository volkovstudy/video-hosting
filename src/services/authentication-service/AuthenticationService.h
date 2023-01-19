#ifndef VIDEO_HOSTING_AUTHENTICATIONSERVICE_H
#define VIDEO_HOSTING_AUTHENTICATIONSERVICE_H


#include <string>

using namespace std;

class AuthenticationService {
public:
    void authenticate(int userId, string password);
};


#endif
