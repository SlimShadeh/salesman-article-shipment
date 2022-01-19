#include "rukovalac.h"

void Rukovalac::obrada(int &brDana, double &cena) {
    brDana+=brDanaObrada;
    cena=cena*realnaMarza;
}

void Rukovalac::prosiri(Artikal &aa, double marza, int brD) {
    a=aa;
    realnaMarza=marza;
    brDanaObrada=brD;

}