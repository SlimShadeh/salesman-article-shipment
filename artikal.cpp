#include "artikal.h"

bool operator==(const Artikal &a1, const Artikal &a2) {
    if(a1.barkod==a2.barkod) return true;
    else return false;
}
