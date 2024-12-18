#include <cctype>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <tuple>

std::tuple<int, int> parseIntsFromMul(std::string mul) {
    int lhs;
    int rhs;
    size_t openParen = mul.find("(");
    size_t comma = mul.find(",");
    size_t closeParen = mul.find(")");

    std::string num;

    num = mul.substr(openParen + 1, comma - openParen - 1);
    std::cout << "Num :" << num << '\n';
    lhs = std::stoi(num);

    num = mul.substr(comma + 1, closeParen - comma - 1);
    rhs = std::stoi(num);

    return std::tuple<int, int>{lhs, rhs};
}

int main() {
    std::ifstream fstream("./input.txt");
    if (!fstream) {
        std::cerr << "Couldn't find input file \n";
    }

    unsigned lines = 0;
    unsigned result = 0;
    std::string instructions = "";
    std::string line;
    while (std::getline(fstream, line)) {
        instructions += line;
        ++lines;
    }

    std::regex pattern{"mul\\([0-9]+,[0-9]+\\)|do\\(\\)|don't\\(\\)"};
    std::sregex_iterator it(instructions.begin(), instructions.end(), pattern);
    std::sregex_iterator end;

    bool doMul = true;
    for (auto i = it; i != end; ++i) {
        std::cout << "Match: " << (*i).str() << '\n';
        if ((*i).str() == "do()") {
            doMul = true;
        } else if ((*i).str() == "don't()") {
            doMul = false;
        } else {
            if (!doMul) {
                continue;
            }
            std::tuple<int, int> res = parseIntsFromMul((*i).str());

            int lhs = 0, rhs = 0;
            lhs = std::get<0>(res);
            rhs = std::get<1>(res);

            //        std::stringstream ss((*i).str());
            //        ss >> lhs;
            //        ss >> rhs;
            std::cout << "lhs: " << lhs << " rhs: " << rhs << '\n';
            result += lhs * rhs;
        }
    }

    std::cout << "Results of mul instructions: " << result << '\n';
    return 0;
}
