#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>
#include "bank.h"

class Итератор {
private:
    std::ifstream reader;
    bool eof;
    Bank current_bank;
    void next() {
        std::stringstream now;
        std::string s;
        eof = !std::getline(reader, s);
        if (!eof) {
            now << s;
            std::string name;
            now>>name;
            std::vector<Ссуда> Ссуды;
            int year, ssuda;
            while (now>>year>>ssuda) {
                Ссуда ssudaa(year, ssuda);
                Ссуды.push_back(ssudaa);
            }
            current_bank = Bank(name, Ссуды);
        }
    }
public:
    Итератор(std::string fs = ""): current_bank(Bank("GOAL")) {
        reader = std::ifstream(fs);
        next();
    }
    bool getEof() {
        return eof;
    }
    bool operator==(Итератор& right) {
        return this->getEof() && right.getEof();
    }
    bool operator!=(Итератор& right) {
        return !(*this==right);
    }
    Bank operator*() {
        return current_bank;
    }
    Итератор& operator++() {
        next();
        return *this;
    }
};

int main() {
    std::vector<Bank> Банки;
    for (Итератор старт("first.txt"), конец; старт != конец; ++старт) {
        std::cout << (*старт).GetName() << std::endl;
        Банки.push_back(*старт);
    }
    return 0;
}