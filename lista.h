#ifndef ZAD2_LISTA_H
#define ZAD2_LISTA_H
#include <iostream>
using namespace std;

class GNemaElementa{
    friend ostream& operator<<(ostream& os,const GNemaElementa &t){
        return os << "***Ne postoji element na datoj poziciji!***\n";

    }
};

template <typename T>
class Lista {
public:
    ~Lista(){
        isprazni();
    }
    Lista(){
        prvi=posl=nullptr;
    }
    Lista(const Lista &l){
        kopiraj(l);
    }
    Lista(Lista &&l){
        premesti(l);
    }
    Lista &operator =(const Lista &l){
        if(this !=&l){
            isprazni();
            kopiraj(l);
        }
        return *this;
    }
    Lista &operator =(Lista &&l){
        if(this !=&l){
            isprazni();
            premesti(l);
        }
        return *this;
    }
    Lista& dodaj(const T& t){
        posl=(!prvi ? prvi :posl->sled)=new Elem (t);
        return *this;
    }

    Lista &operator+=(const T& t){
        dodaj(t);
        return *this;
    }

    T &operator[](int i){
        int br=0;
        for(Elem *pok=prvi;pok;pok=pok->sled){
            if(i==br) return pok->pod;
            br++;
        }
        throw GNemaElementa();
    }
    int dohvBrojElemenata()const {
        int br=0;
        for(Elem *pok=prvi;pok;pok=pok->sled){
            br++;
        }
        return br;
    }

private:
    struct Elem {
        T pod;
        Elem *sled;
        Elem(const T& p, Elem *s=nullptr) : pod(p){
            sled=s;
        }
    };
    Elem *prvi,*posl;

    void isprazni();
    void kopiraj(const Lista &l);
    void premesti(Lista &l) {
        prvi=l.prvi;
        posl=l.posl;
        l.prvi=l.posl=nullptr;
    };
};

template <typename T>
void Lista<T>::kopiraj(const Lista<T> &l) {
    prvi=posl=nullptr;
    for(Elem *pok=l.prvi;pok;pok=pok->sled){
        Elem *novi =new Elem(pok->pod);
        posl=(!prvi ? prvi : posl->sled)=novi;
    }
}

template <typename T>
void Lista<T>::isprazni() {
    while(prvi){
        Elem *stari=prvi;
        prvi=prvi->sled;
        delete stari;
    }
    posl=nullptr;
}



#endif //ZAD2_LISTA_H
