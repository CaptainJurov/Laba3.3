#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>
#include <iterator>
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
                // std::cout<<year<<" "<<ssuda<<std::endl;
                Ссуды.push_back(ssudaa);
            }
            current_bank = Bank(name, Ссуды);
            std::cout<<"[Filereader]>"<<current_bank.GetName()<<std::endl;
            for (auto a = current_bank.GetSsuds().begin(); a!=current_bank.GetSsuds().end();++a) {
                std::cout<<"[Filereader]>"<<(*a).Год<<" "<<(*a).Ссуда_<<std::endl;
            }
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
    std::vector<Bank> Банки = {};
    for (Итератор старт("first.txt"), конец; старт != конец; ++старт) {
        Банки.push_back(Bank(*старт));
    }
    for (auto st = Банки.begin();st!=Банки.end();++st ) {
        std::cout<<(*st).GetName()<<std::endl;
        for (auto elem = (*st).GetSsuds().begin(); elem!=(*st).GetSsuds().end(); ++elem) {
            std::cout<<"Год: "<<(*elem).Год<<" | Ссуда: "<<(*elem).Ссуда_<<std::endl;
        }
    }


    return 0;
}