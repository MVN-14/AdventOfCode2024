#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

bool isSafeWithRemoval(std::string report) {
    bool removedOne = false;
    std::stringstream ss(report);
    unsigned long num = 0, lastNum = 0;
    bool ascending = true;

    ss >> lastNum;
    ss >> num;
    if (num > lastNum) {
        ascending = true;
    } else if (num < lastNum) {
        ascending = false;
    } else {
        return false;
    }

    do {
        if (ascending) {
            if (num - lastNum > 3 || num - lastNum <= 0) {
                if (!removedOne) {

                    removedOne = true;
                    continue;
                } else {
                    return false;
                }
            }
        } else {
            if (lastNum - num > 3 || lastNum - num <= 0) {
                if (!removedOne) {
                    removedOne = true;
                    continue;
                } else {
                    return false;
                }
            }
        }
        lastNum = num;
    } while (ss >> num);

    return true;
}

int main() {
    std::ifstream fstream("./small-input.txt");
    if (!fstream) {
        std::cerr << "Couldn't find input file \n";
    }

    std::string line;
    unsigned safeReports = 0;
    unsigned lines = 0;
    while (std::getline(fstream, line)) {
        if (isSafeWithRemoval(line)) {
            ++safeReports;
        }
        ++lines;
    }

    std::cout << "Safe Reports: " << safeReports << " in " << lines << " lines"
              << '\n';

    return 0;
}
