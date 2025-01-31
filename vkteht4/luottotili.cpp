#include "luottotili.h"

Luottotili::Luottotili(string u, double r) : Pankkitili(u){
    omistaja = u;
    luottoRaja = r;
    cout << "Luottotili luotu: " << u;
    cout << ", luottoraja: " << r << endl;
}

bool Luottotili::deposit(double s) //velanmaksu
{
    cout << "Talleta luottotilille haluttu summa: ";
    cin >> s;

    if (s < 0){
        cout << "Et voi tallettaa negatiivista summaa" << endl;
        return false;
    }
    else if (luottoRaja > 1000){
        cout << "Luoton saldo ei voi olla yli 1000" << endl;
        return false;
    }
    else {
        luottoRaja = luottoRaja + s;
        cout << "Velanmaksu tehty: " << s << endl;
        //cout << "Luoton tilanne: " << luottoRaja << endl;
        return true;
    }
}

bool Luottotili::withdraw(double s) //nosto
{
    cout << "Nosta luottotililta haluttu summa: ";
    cin >> s;


    if (s < 0){
        cout << "Et voi nostaa negatiivista summaa" << endl;
        return false;
    }
    else if (luottoRaja < 0){
        cout << "Et suorittaa nostoa jos saldo menee yli 0" << endl;
        return false;
    }
    else {
        luottoRaja = luottoRaja - s;
        cout << "Nosto tehty: " << s << endl;
        //cout << "Luottoa jaljella: " << luottoRaja << endl;
        return true;
    }
}

double Luottotili::getCreditBalance()
{
    cout << "Luottotilin saldo: " << luottoRaja << endl;
    return luottoRaja;
}
