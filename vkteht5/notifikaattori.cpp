#include "notifikaattori.h"

Notifikaattori::Notifikaattori(){
    cout << "Luodaan notifikaattori" << endl;
}

void Notifikaattori::lisaa(Seuraaja *name)
{
    cout << "Notifikaatori lisaa seuraajan: " << name->getNimi() << endl;
    name->next = seuraajat;
    seuraajat = name;

}

void Notifikaattori::tulosta()
{   // tulostetaan kaikki seuraajat
    Seuraaja *nykyinen = seuraajat;
    while (nykyinen != nullptr){
        cout << "Seuraaja: " << nykyinen->getNimi() << endl;
        nykyinen = nykyinen->next;
    }
}

void Notifikaattori::poista(Seuraaja *dlt)
{
    // poistetaan solmusta ensimmäinen seuraaja
    if (seuraajat == dlt){
        seuraajat = seuraajat->next;
        cout << "Notifikaattori poisti seuraajan: " << dlt->getNimi() << endl;
        return;
    }

    Seuraaja *nykyinen = seuraajat;
    while (nykyinen->next){ //käydään lista läpi
        if (nykyinen->next == dlt){ //löydettiin poistettava seuraaja
            nykyinen->next = dlt->next; //ohitetaan seuraaja
            cout << "Notifikaattori poisti seuraajan: " << dlt->getNimi() << endl;
            return;
        }
        nykyinen = nykyinen->next;
    }

}

void Notifikaattori::postita(string viesti)
{
    cout << "Notifikaattori postaa viestin: " << viesti << endl;
    Seuraaja *nykyinen = seuraajat;
    while (nykyinen != nullptr){
        nykyinen->paivitys(viesti);
        nykyinen = nykyinen->next;
    }
}
