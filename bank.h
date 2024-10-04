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
    Ссуда() = default;
};

//---------------------------------------------------------

class Bank {
private:
    std::string Название;
    std::vector<Ссуда> Ссуды;
public:
    Bank(std::string name, std::vector<Ссуда> Ssuds) {
        Название = name;
        Ссуды = Ssuds;
    }
    Bank(): Название(""), Ссуды() {}
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
    std::ifstream& read(std::ifstream& in)
    {
        size_t len;                         
        in.read((char*)&len, sizeof(len));  
        char * buf = new char[len];         
        in.read(buf,len);                   
        Название = buf;                  
        delete[]buf;


        Ссуды.clear();
        size_t sz;
        in.read((char*)&sz,sizeof(sz));
        for(int i = 0; i < sz; ++i)
        {
            Ссуда ссуда;
            in.read((char*)&ссуда, sizeof(Ссуда));
            Ссуды.push_back(ссуда);
        }
        return in;
    }

    std::ofstream& write(std::ofstream& out)
    {
        //https://ru.stackoverflow.com/questions/650106/%D0%97%D0%B0%D0%BF%D0%B8%D1%81%D1%8C-string-%D0%B2-%D0%B1%D0%B8%D0%BD%D0%B0%D1%80%D1%8B%D0%B9-%D1%84%D0%B0%D0%B9%D0%BB-%D0%A1
        size_t sz_str = Название.length()+1;
        out.write((char*)&sz_str, sizeof(sz_str));
        out.write((char*)Название.c_str(),sz_str);

        //https://ru.stackoverflow.com/questions/919792/%D0%97%D0%B0%D0%BF%D0%B8%D1%81%D0%B0%D1%82%D1%8C-%D0%B8-%D1%81%D1%87%D0%B8%D1%82%D0%B0%D1%82%D1%8C-%D1%81%D0%BB%D0%BE%D0%B6%D0%BD%D1%8B%D0%B9-%D0%BE%D0%B1%D1%8A%D0%B5%D0%BA%D1%82-%D0%BA%D0%BB%D0%B0%D1%81%D1%81%D0%B0-%D0%B8%D0%B7-%D0%B1%D0%B8%D0%BD%D0%B0%D1%80%D0%BD%D0%B8%D0%BA%D0%B0-c
        size_t sz = Ссуды.size();
        out.write((char*)&sz, sizeof(sz));
        for(int i = 0; i < sz; ++i)
        {
            out.write((char*)&Ссуды[i],sizeof(Ссуда));
        }
        return out;
    }

    std::vector<Ссуда>& GetSsuds() {
        return Ссуды;
    }
    std::string GetName() {
        return Название;
    }
};

//---------------------------------------------------------------

// ASS - Associated Serialized Structure
// + Банк =
// 1 Man 1 Cup

struct ASS {
    std::vector<Bank> Банки;
    
    ASS()=default;

    void load(std::string fs) {
        std::ifstream fin(fs, std::ios::binary);
        size_t len;
        fin.read((char*)&len, sizeof(len));
        for (int i = 0; i<len; ++i) {
            Bank tmp;
            tmp.read(fin);
            Банки.push_back(tmp);
        }
        fin.close();
    }

    void save(std::string fs) {
        
        std::ofstream gog(fs, std::ios::binary);
        size_t len = Банки.size();
        gog.write((char*)&len, sizeof(len));

        for (auto& bank : Банки) {
            bank.write(gog);
        }
        gog.close();
    }
};