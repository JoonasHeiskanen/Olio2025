#include "seuraaja.h"

Seuraaja::Seuraaja(string n){
    nimi = n;
    cout << "Seuraaja luotu: " << n << endl;
}

string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(string viesti) //funktiota kutsutaan postita funktiossa
{
    cout << "Seuraaja " << nimi << " sai viestin: " << viesti << endl;
}
