#pragma once
#include <vector>
#include <string>
struct Ссуда {
    int Год;
    int Ссуда_;
    Ссуда(int Год, int Ссуда_) {
        this->Год = Год;
        this->Ссуда_ = Ссуда_;
    }
};
class Bank {
private:
    std::string Название;
    std::vector<Ссуда> Ссуды;
public:
    Bank(std::string name, std::vector<Ссуда> Ssuds) {
        Название = name;
        Ссуды = Ssuds;
    }
    Bank(std::string name) {
        this->Название = name;
    }
    Bank(const Bank& other) {
        Название = other.Название;
        Ссуды = other.Ссуды;
    }
    void AppendSSud(Ссуда ssud) {
        Ссуды.push_back(ssud);
    }
    std::vector<Ссуда>& GetSsuds() {
        return Ссуды;
    }
    std::string GetName() {
        return Название;
    }
};