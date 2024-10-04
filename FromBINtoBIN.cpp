#include <iostream>
#include <fstream>
#include "bank.h"
#include <vector>
int main() {
    ASS *Obj = new ASS();
    Obj->load("goal.biba");

    auto *восстановленные_банки = &(Obj->Банки);
    
    std::cout<<"end read\n";
    for (auto& bank : *восстановленные_банки) {
        std::cout<<bank.GetName()<<std::endl;
        for (const auto& elem : bank.GetSsuds() ) {
            std::cout<<"Год: "<<elem.Год<<" | Ссуда: "<<elem.Ссуда_<<std::endl;
        }
    }

    std::cout<<"\n=--=-=--=\nЛиквидируем банки с общей ссудой меньше 100 тыс.\n=--=-=--=\n"<<std::endl;
    std::cout<<восстановленные_банки->size()<<std::endl;
    for (auto bank = восстановленные_банки->begin(); bank!=восстановленные_банки->end(); ) {
        int Суммарная_Ссуда = 0;
        for (auto& Ssuda : (*bank).GetSsuds()) {
            Суммарная_Ссуда += Ssuda.Ссуда_;
        }
        std::cout<<Суммарная_Ссуда<<"\n";
        if (Суммарная_Ссуда<100) {
            восстановленные_банки->erase(bank);
            std::cout<<восстановленные_банки->size()<<std::endl;
            
        }
        else {++bank;}
    }

    for (auto& bank : *восстановленные_банки) {
        std::cout<<bank.GetName()<<std::endl;
        for (const auto& elem : bank.GetSsuds() ) {
            std::cout<<"Год: "<<elem.Год<<" | Ссуда: "<<elem.Ссуда_<<std::endl;
        }
    }


    std::cout<<"end\n";
}