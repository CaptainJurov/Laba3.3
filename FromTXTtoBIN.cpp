#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>
#include <iterator>
#include "bank.h"
#include <stdio.h>

class Итератор {
private:
    std::ifstream reader;
    bool eof;
    std::stringstream current_ss;
    void next() {
        std::string s;
        current_ss.clear();
        current_ss.str("");
        eof = !std::getline(reader, s);
        current_ss << s;
    }
public:
    Итератор(std::string fs = "") {
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
    std::stringstream& operator*() {
        return current_ss;
    }
    Итератор& operator++() {
        next();
        return *this;
    }
};
Bank Parse(std::stringstream& now) {
    std::string name;
    now>>name;
    std::vector<Ссуда> Ссуды;
    int year, ssuda;
    while (now>>year>>ssuda) {
        Ссуда ssudaa(year, ssuda);
        Ссуды.push_back(ssudaa);
    }
    Bank current_bank(name, Ссуды);
    std::cout<<"[SSParse]>"<<current_bank.GetName()<<std::endl;
    for (auto a = current_bank.GetSsuds().begin(); a!=current_bank.GetSsuds().end();++a) {
        std::cout<<"[SSParse]>"<<(*a).Год<<" "<<(*a).Ссуда_<<std::endl;
    }
    return current_bank;
}
int main() {
    ASS *Obj = new ASS();
    //std::vector<Bank> Банки = {};
    auto *Банки = &(Obj->Банки);
    for (Итератор старт("first.txt"), конец; старт != конец; ++старт) {
        Банки->push_back(Bank(Parse(*старт)));
    }
    for (auto st = Банки->begin();st!=Банки->end();++st ) {
        std::cout<<(*st).GetName()<<std::endl;
        for (auto elem = (*st).GetSsuds().begin(); elem!=(*st).GetSsuds().end(); ++elem) {
            std::cout<<"Год: "<<(*elem).Год<<" | Ссуда: "<<(*elem).Ссуда_<<std::endl;
        }
    }
    
    Obj->save("goal.biba");
    return 0;
}