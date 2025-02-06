#include <iostream>
#include "seuraaja.h"
#include "notifikaattori.h"
using namespace std;

int main()
{
    Notifikaattori n;

    Seuraaja A("Alffa");
    Seuraaja B("Bertta");
    Seuraaja C("Charlie");

    n.lisaa(&A);
    n.lisaa(&B);
    n.lisaa(&C);
    n.tulosta();

    n.postita("Tama on viesti 1");

    n.poista(&B);
    n.poista(&A);

    n.postita("Tama on viesti 2");
    n.tulosta();


    return 0;
}
