#ifndef VIDEO_HOSTING_FILESERVICE_H
#define VIDEO_HOSTING_FILESERVICE_H


#include <fstream>
#include <string>
#include <vector>

using namespace std;

class FileService {
private:
    string _filePath;
public:
    explicit FileService(const string &filePath);

    vector<string> readAll();

    void write(const string& data);
};


#endif
