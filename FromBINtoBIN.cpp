#include <iostream>
#include <fstream>
#include "bank.h"
#include <vector>
int main() {
    ASS *Obj = new ASS();
    //Obj->load("goal.biba");
    std::ifstream z("goal.biba", std::ios::binary);
    Bank tmp;
    while (z.peek()!=EOF) {
        z>>tmp;
        Obj->Банки.push_back(Bank(tmp));
    }
    z.close();
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
    
    for (auto& bank : *восстановленные_банки) {
        std::cout<<bank.GetName()<<"---------"<<std::endl;

        копия->push_back(Bank(bank));
        
        for (const auto& elem : bank.GetSsuds() ) {
            std::cout<<"Год: "<<elem.Год<<" | Ссуда: "<<elem.Ссуда_<<std::endl;
        }
        std::cout<<std::endl;
    }

    std::ofstream v("third.gotovo", std::ios::binary);
    for (auto& bank : *восстановленные_банки) {
        v<<bank;
    }
    v.close();
    delete Obj;
    std::cout<<"Главный обьект удален, вывожу копию:"<<std::endl;


    копия->sort([](Bank& a, Bank& b) { return a.GetSumSSud() < b.GetSumSSud();});

    for (auto& bank : *копия) {
        std::cout<<bank.GetName()<<"---------"<<std::endl;
        for (const auto& elem : bank.GetSsuds() ) {
            std::cout<<"Год: "<<elem.Год<<" | Ссуда: "<<elem.Ссуда_<<std::endl;
        }
        std::cout<<std::endl;
    }

}