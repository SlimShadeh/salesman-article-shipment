#ifndef ZAD2_ARTIKAL_H
#define ZAD2_ARTIKAL_H
#include <string>
using namespace std;

class Artikal {
public:
    Artikal(string naz,int bar,double nabCena){
        naziv=naz;
        barkod=bar;
        nabavnaCena=nabCena;
    }
    virtual ~Artikal()=default;

    const string &dohvNaziv() const {
        return naziv;
    }
    int dohvBarkod() const {
        return barkod;
    }
    double dohvNabavnaCena() const {
        return nabavnaCena;
    }

    friend bool operator==(const Artikal &a1,const Artikal &a2);

private:
    string naziv;
    int barkod;
    double nabavnaCena;
};


#endif //ZAD2_ARTIKAL_H
