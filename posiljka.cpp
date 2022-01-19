#include "posiljka.h"

int Posiljka::redniBroj=0;

Posiljka &Posiljka::operator+=(const Rukovalac &rr) {
    if(obradjen==OBRADJENA) throw GObradjen();
    r+=rr;
    return *this;
}

int Posiljka::getId() const {
    return id;
}

const Artikal &Posiljka::getArtikal() const {
    return a;
}

ostream &operator<<(ostream &os, const Posiljka &p) {
    return os << "Posiljka[" << p.id << ", " << p.a.dohvNaziv() <<']';
}

void Posiljka::obrada() {
    int n=r.dohvBrojElemenata();
    double ukupnaCena=0;

    for(int i=0;i<n;i++){
        double cena=a.dohvNabavnaCena();
        r[i].obrada(detalji.brDana,cena);
        ukupnaCena+=cena;
    }
    detalji.cena=ukupnaCena;
    obradjen=OBRADJENA;
}

const Posiljka::Elem &Posiljka::getDetalji() const {
    if(obradjen==NEOBRADJENA) throw GNeobradjen();
    return detalji;
}
