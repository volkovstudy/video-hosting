#include "FileService.h"

FileService::FileService(const string &filePath) : _filePath(filePath) {}

vector<string> FileService::readAll() {
    ifstream input(_filePath);

    vector<string> result;

    string line;
    while (getline(input, line)) {
        if (line.empty()) break;

        result.push_back(line);
    }

    return result;
}

void FileService::write(const string &data) {
    ofstream output(_filePath, ios::app);

    output << data << endl;

    output.close();
}
