#include <iostream>
#include <fstream>
#include "bank.h"
#include <vector>
int main() {
    ASS *Obj = new ASS();
    auto *восстановленные_банки = &(Obj->Банки);
    Obj->load("goal.biba");
    std::cout<<"end read\n";
    for (auto& bank : *восстановленные_банки) {
        std::cout<<bank.GetName()<<std::endl;
        for (const auto& elem : bank.GetSsuds() ) {
            std::cout<<"Год: "<<elem.Год<<" | Ссуда: "<<elem.Ссуда_<<std::endl;
        }
    }
    std::cout<<"end\n";
}