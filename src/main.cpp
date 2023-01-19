#include <iostream>
#include "services/file-service/FileService.h"

int main() {
    FileService fileService("test.txt");

    fileService.write("test data");
    fileService.write("another line of data");

    vector<string> lines = fileService.readAll();

    for (const string& line: lines) {
        cout << line << endl;
    }

    return 0;
}
