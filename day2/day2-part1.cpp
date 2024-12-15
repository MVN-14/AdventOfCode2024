#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

bool isReportSafe(std::string report) {
    std::stringstream ss(report);
    unsigned long num, lastNum;
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
                return false;
            }
        } else {
            if (lastNum - num > 3 || lastNum - num <= 0) {
                return false;
            }
        }
        lastNum = num;
    } while (ss >> num);

    return true;
}

int main() {
    std::ifstream fstream("./input.txt");
    if (!fstream) {
        std::cerr << "Couldn't find input file \n";
    }

    std::string line;
    unsigned safeReports = 0;
    unsigned lines = 0;
    while (std::getline(fstream, line)) {
        if (isReportSafe(line)) {
            ++safeReports;
        }
        ++lines;
    }

    std::cout << "Safe Reports: " << safeReports << " in " << lines << " lines"
              << '\n';

    return 0;
}
