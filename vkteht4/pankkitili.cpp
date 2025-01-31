#include "pankkitili.h"

Pankkitili::Pankkitili(string u){
    omistaja = u;
    cout << "Pankkitili Luotu: " << u << endl;
}

double Pankkitili::getBalance()
{
    cout << "Kayttotilin saldo: " << saldo << endl;
    return saldo;
}

bool Pankkitili::deposit(double s) //talletus
{
    cout << "Talleta pankkitilille haluttu summa: ";
    cin >> s;

    if (s < 0){
        cout << "Et voi tallettaa negatiivista summaa" << endl;
        return false;
    }
    else {
        saldo = saldo + s;
        cout << "Talletus tehty: " << s << endl;
        return true;
    }
}

bool Pankkitili::withdraw(double s) //nosto
{
    cout << "Nosta pankkitililta haluttu summa: ";
    cin >> s;


    if (s < 0){
        cout << "Et voi nostaa negatiivista summaa" << endl;
        return false;
    }
        else if (saldo < s){
        cout << "Et suorittaa nostoa jos katetta ei ole tarpeeksi" << endl;
        return false;
        }
    else {
        saldo = saldo - s;
        cout << "Nosto tehty: " << s << endl;
        return true;
    }
}
