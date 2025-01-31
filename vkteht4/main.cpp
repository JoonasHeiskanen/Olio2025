#include <iostream>
#include "pankkitili.h"
#include "luottotili.h"
#include "asiakas.h"

using namespace std;

int main()
{
    /*Pankkitili olio("Joonas");

    olio.getBalance();

    int s = 0;
    olio.deposit(s);
    olio.getBalance();

    olio.withdraw(s);
    olio.getBalance();

    Luottotili tili2("Uolevi", 1000);

    tili2.withdraw(s);
    tili2.deposit(s);*/

    Asiakas user2("Pertti", 1000);
    //int i = 0;
    user2.showSaldo();
    cout << endl;

    Asiakas user("Joonas", 1000);
    double s = 0;
    user.talletus(s);
    user.showSaldo();
    user.tiliSiirto(s, user2);
    user2.showSaldo();
    user.showSaldo();
    /*user.luotonNosto(s);
    user.showSaldo();
    user.nosto(s);
    user.luotonMaksu(s);
    user.showSaldo();*/


    return 0;
}
