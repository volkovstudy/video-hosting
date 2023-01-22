#include <cassert>

#include "services/utils/Utils.h"

void shouldSplitIntoStrings();

int main() {
    shouldSplitIntoStrings();
}

void shouldSplitIntoStrings() {
    string line = "test,another,big one";
    char delimiter = ',';

    vector<string> lineContent = Utils::split(line, delimiter);

    assert(lineContent.at(0) == "test");
    assert(lineContent.at(1) == "another");
    assert(lineContent.at(2) == "big one");
}
