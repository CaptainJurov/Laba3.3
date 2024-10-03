#include <iostream>
#include <fstream>
#include "bank.h"
#include <vector>
int main() {
    std::vector<Bank> восстановленные_банки;
    std::cout<<"start reading\n";
    // Перебор элементов вектора
    
    std::ifstream fin("binf.goal", std::ios::binary);
while (true) {
    size_t name_length;
    if (!fin.read(reinterpret_cast<char*>(&name_length), sizeof(name_length))) 
        break; // Если чтение не удалось, выходим из цикла

    std::string name(name_length, ' ');
    fin.read(&name[0], name_length);

    size_t ssud_count;
    fin.read(reinterpret_cast<char*>(&ssud_count), sizeof(ssud_count));

    Bank bank(name);
    for (size_t i = 0; i < ssud_count; ++i) {
        Ссуда ssud(0, 0); // Начальное значение
        fin.read(reinterpret_cast<char*>(&ssud.Год), sizeof(ssud.Год));
        fin.read(reinterpret_cast<char*>(&ssud.Ссуда_), sizeof(ssud.Ссуда_));
        bank.AppendSSud(ssud);
    }
    восстановленные_банки.push_back(bank);
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