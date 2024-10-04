#include <iostream>
#include <fstream>
#include "bank.h"
#include <vector>
int main() {
    std::vector<Bank> восстановленные_банки;
    std::cout<<"start reading\n";
    std::ifstream fin("binf.goal", std::ios::binary);
    size_t len;
    fin.read((char*)&len, sizeof(len));
    for (int i = 0; i<len; ++i) {
        Bank tmp;
        tmp.read(fin);
        восстановленные_банки.push_back(tmp);
    }
fin.close();
    std::cout<<"end read\n";
    for (auto& bank : восстановленные_банки) {
        std::cout<<bank.GetName()<<std::endl;
        for (const auto& elem : bank.GetSsuds() ) {
            std::cout<<"Год: "<<elem.Год<<" | Ссуда: "<<elem.Ссуда_<<std::endl;
        }
    }
    std::cout<<"end\n";
}