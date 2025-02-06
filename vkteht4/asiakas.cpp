#include "asiakas.h"

Asiakas::Asiakas(string u, double r)
    : /*nimi(u),*/ kayttotili(u), luottotili(u,r){
    // välitetään pankki- ja luottotilin parametrit konstruktoriin
    nimi = u; //otetaan private muuttuja asiakas.h filestä
    cout << "Asiakas luotu: " << nimi << endl;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout << "Asiakkaan " << nimi << " saldot ovat:" << endl;
    kayttotili.getBalance();
    luottotili.getCreditBalance();
}

bool Asiakas::talletus(double s)
{
    return kayttotili.deposit(s);
}

bool Asiakas::nosto(double s)
{
    return kayttotili.withdraw(s);
}

bool Asiakas::luotonMaksu(double s)
{
    return luottotili.deposit(s);
}

bool Asiakas::luotonNosto(double s)
{
    return luottotili.withdraw(s);

    /*if (!luottotili.withdraw(s)){
        cout << "Luoton nosto epäonnistui, tarkista luottoraja" << endl;
        return false;
    }
    return true;*/
}

bool Asiakas::tiliSiirto(double summa, Asiakas &Pertti)
{   // Suoritetaan tilisiirto userilta --> user2
    cout << "Nosta tililta haluttu summa ja siirra se tilille Pertti" << endl;
    if (!kayttotili.withdraw(summa) || !Pertti.talletus(summa)){
        return false;
    }
    else{ cout << "Summa siirretty onnistuneesti!" << endl;
        return true;

    }
}
