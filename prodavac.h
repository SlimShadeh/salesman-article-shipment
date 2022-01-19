#ifndef ZAD2_PRODAVAC_H
#define ZAD2_PRODAVAC_H
#include "rukovalac.h"

class Prodavac : public Rukovalac {
public:
    Prodavac(string naz) : Rukovalac(naz) {  };

    ~Prodavac()=default;

    string dohvNaziv() const;
};


#endif //ZAD2_PRODAVAC_H
