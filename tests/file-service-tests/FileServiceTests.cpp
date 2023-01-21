#include <cassert>

#include "services/file-service/FileService.h"

#define testFile "file-service-test.txt"

void shouldReadAllDataFromFile();

int main() {
    shouldReadAllDataFromFile();
    ::remove(testFile);

    return 0;
}

void writeVectorToFile(vector<string> data, FileService& fileService) {
    for (const auto& item: data) {
        fileService.write(item);
    }
}

void shouldReadAllDataFromFile() {
    FileService fileService(testFile);

    // Given
    vector<string> data = {"test", "new test", "qwerty"};
    writeVectorToFile(data, fileService);

    // When
    vector<string> lines = fileService.readAll();

    assert(data == lines);
}
