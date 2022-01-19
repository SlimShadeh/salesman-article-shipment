#ifndef ZAD2_POSILJKA_H
#define ZAD2_POSILJKA_H
#include "artikal.h"
#include "rukovalac.h"
#include "lista.h"

class GNeobradjen{
    friend ostream& operator<<(ostream& os,const GNeobradjen &t){
        return os << "***Nije moguce dobiti detalje posiljke jer ona nije obradjena!***\n";

    }
};

class GObradjen{
    friend ostream& operator<<(ostream& os,const GObradjen &t){
        return os << "***Nije moguce dodati rukovaoca jer je posiljka vec obradjena!***\n";

    }
};

enum vrsta{NEOBRADJENA,OBRADJENA};
class Posiljka {
public:
    struct Elem {
        int brDana;
        double cena;
        Elem(int brD=0,double c=0){
            brDana=brD;
            cena=c;
        }
    };

    static int redniBroj;
    Posiljka(Artikal &art) : a(art) ,detalji(){
        id=redniBroj;
        redniBroj++;
        obradjen=NEOBRADJENA;
    }

    Posiljka &operator +=(const Rukovalac &r);

    friend ostream &operator<<(ostream &os,const Posiljka &p);

    int getId() const;

    const Artikal &getArtikal() const;

    const Elem &getDetalji() const;

    void obrada();

private:
    int id;

    Elem detalji;
    vrsta obradjen;
    Artikal a;
    Lista <Rukovalac> r;
};


#endif //ZAD2_POSILJKA_H
