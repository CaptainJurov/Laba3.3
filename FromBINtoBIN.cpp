#include <iostream>
#include <fstream>
#include "bank.h"
#include <vector>
int main() {
    ASS *Obj = new ASS();
    Obj->load("goal.biba");

    auto *восстановленные_банки = &(Obj->Банки);
    
    for (auto& bank : *восстановленные_банки) {
        std::cout<<bank.GetName()<<"--------"<<std::endl;
        for (const auto& elem : bank.GetSsuds() ) {
            std::cout<<"Год: "<<elem.Год<<" | Ссуда: "<<elem.Ссуда_<<std::endl;
        }
        std::cout<<std::endl;
    }

    std::cout<<"\n=--=-=--=\nЛиквидируем банки с общей ссудой меньше 100 тыс.\n=--=-=--=\n"<<std::endl;
    for (auto bank = восстановленные_банки->begin(); bank!=восстановленные_банки->end(); ) {
        if (bank->GetSumSSud()<100) {
            auto cope = bank;
            ++cope;
            восстановленные_банки->erase(bank);
            bank = cope;
        }
        else {++bank;}
    }
    
    ASS *Копия = new ASS();
    auto *копия = &(Копия->Банки);

    восстановленные_банки->sort([](Bank& a, Bank& b) { return a.GetSumSSud() > b.GetSumSSud();});
    
    for (auto& bank : *восстановленные_банки) {
        std::cout<<bank.GetName()<<"---------"<<std::endl;

        копия->push_back(Bank(bank));
        
        for (const auto& elem : bank.GetSsuds() ) {
            std::cout<<"Год: "<<elem.Год<<" | Ссуда: "<<elem.Ссуда_<<std::endl;
        }
        std::cout<<std::endl;
    }
    
    Obj->save("third.gotovo");
    std::cout<<"Главный обьект удален, вывожу копию:"<<std::endl;
    delete Obj;

    for (auto& bank : *копия) {
        std::cout<<bank.GetName()<<"---------"<<std::endl;
        for (const auto& elem : bank.GetSsuds() ) {
            std::cout<<"Год: "<<elem.Год<<" | Ссуда: "<<elem.Ссуда_<<std::endl;
        }
        std::cout<<std::endl;
    }

}