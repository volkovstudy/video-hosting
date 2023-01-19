#ifndef VIDEO_HOSTING_FILESERVICE_H
#define VIDEO_HOSTING_FILESERVICE_H


#include <fstream>
#include <string>

using namespace std;

class FileService {
private:
    string _filePath;
public:
    explicit FileService(const string &filePath);

    void write(const string& data);
};


#endif
