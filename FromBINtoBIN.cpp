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
    for (auto bank = восстановленные_банки->begin(); bank!=восстановленные_банки->end(); ) {
        int Суммарная_Ссуда = 0;
        for (auto& Ssuda : (*bank).GetSsuds()) {
            Суммарная_Ссуда += Ssuda.Ссуда_;
        }
        if (Суммарная_Ссуда<100) {
            auto cope = bank;
            ++cope;
            восстановленные_банки->erase(bank);
            bank = cope;
        }
        else {++bank;}
    }

    for (auto& bank : *восстановленные_банки) {
        std::cout<<bank.GetName()<<std::endl;
        for (const auto& elem : bank.GetSsuds() ) {
            std::cout<<"Год: "<<elem.Год<<" | Ссуда: "<<elem.Ссуда_<<std::endl;
        }
    }

    Obj->save("second.gotovo");
}