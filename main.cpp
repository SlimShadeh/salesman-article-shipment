#include "artikal.h"
#include "posiljka.h"
#include "prodavac.h"
int main() {

    Artikal a("Smoki",9999,500);
    /*
    Artikal a2("kikiriki",1234,100.50);
    if(a==a2) cout <<"isto je\n";
    else cout <<"nije isto\n";
    */
    Prodavac r("petar");
    r.prosiri(a,1.3,2);
    Posiljka p(a);
    //Posiljka p2(a);
    p+=r;
    p.obrada();
    cout <<p <<"\n";
    cout <<p.getDetalji().brDana <<"\n" << p.getDetalji().cena;
    return 0;
}
