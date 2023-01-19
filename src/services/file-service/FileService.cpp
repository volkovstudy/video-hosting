#include "FileService.h"

FileService::FileService(const string &filePath) : _filePath(filePath) {}

void FileService::write(const string &data) {
    ofstream output(_filePath, ios::app);

    output << data << endl;

    output.close();
}
