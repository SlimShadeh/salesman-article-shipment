#ifndef ZAD2_RUKOVALAC_H
#define ZAD2_RUKOVALAC_H
#include "artikal.h"

class Rukovalac {
public:
    Rukovalac(string naz) : a("NEODREDJEN",-1,-1){
        naziv=naz;
    }
    virtual ~Rukovalac()=default;


    void prosiri(Artikal &aa,double marza,int brD);

    void obrada(int &brDana,double &cena);

protected:
    string naziv;
    Artikal a;
    int brDanaObrada;
    double realnaMarza;
};

#endif //ZAD2_RUKOVALAC_H
