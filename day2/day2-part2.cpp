#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool isReportSafe(std::vector<long> report) {
    bool ascending = true;
    long num = report[1];
    long lastNum = report[0];

    if (num > lastNum) {
        ascending = true;
    } else if (num < lastNum) {
        ascending = false;
    } else {
        return false;
    }

    for (int i = 1; i < report.size(); ++i) {
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
        num = report[i + 1];
    };

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
        std::stringstream ss(line);
        std::vector<long> nums;
        long num;
        while (ss >> num) {
            nums.push_back(num);
        }

        if (isReportSafe(nums)) {
            ++safeReports;
        } else {

            for (int i = 0; i < nums.size(); ++i) {
                std::vector<long> testNums = nums;
                testNums.erase(testNums.begin() + i);

                if (isReportSafe(testNums)) {
                    ++safeReports;
                    break;
                }
            }
        }

        ++lines;
    }

    std::cout << "Safe Reports: " << safeReports << " in " << lines << " lines"
              << '\n';

    return 0;
}
