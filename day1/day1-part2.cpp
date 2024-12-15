#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

unsigned long getDistance(unsigned long lhs, unsigned long rhs) {
    return std::max(lhs, rhs) - std::min(lhs, rhs);
}

int main() {
    std::vector<unsigned long> lhs;
    std::vector<unsigned long> rhs;

    std::ifstream fstream("./input.txt");
    if (!fstream) {
        std::cerr << "Couldn't find input file \n";
    }

    std::stringstream sstream;
    std::string line;

    int l, r;
    while (fstream >> l >> r) {
        lhs.push_back(l);
        rhs.push_back(r);
    }

    // std::sort(lhs.begin(), lhs.end(), [](unsigned long a, unsigned long b) {
    // return a <= b; }); std::sort(rhs.begin(), rhs.end(), [](unsigned long a,
    // unsigned long b) { return a <= b; });

    /* std::cout << "LHS:\n";
    for (int i = 0; i < lhs.size(); ++i) {
        std::cout << lhs[i] << '\n';
    }

    std::cout << "RHS:\n";
    for (int i = 0; i < rhs.size(); ++i) {
        std::cout << rhs[i] << '\n';
    } */

    std::map<unsigned long, unsigned long> frequency;
    for (int i = 0; i < rhs.size(); ++i) {
        ++frequency[rhs[i]];
    }

    unsigned long similarity = 0;
    for (int i = 0; i < lhs.size(); ++i) {
        similarity += lhs[i] * frequency[lhs[i]];
    }

    std::cout << "Similarity: " << similarity << '\n';

    return 0;
}
