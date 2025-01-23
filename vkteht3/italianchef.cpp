#include "italianchef.h"

ItalianChef::ItalianChef(string s) : Chef(s)
{
    cout << "Italianchef created: " << getName() << endl;
}

ItalianChef::~ItalianChef()
{
    cout << "Italianchef destroyed: " << getName() << endl;
}

bool ItalianChef::askSecret(string p, int f, int w)
{
    cout << "Give password for making pizza" << endl;
    cin >> p;
    if(password.compare(p)==0){
        makepizza(f, w);
        cout << "Password ok!" << endl;
        return true;
    }
    else {
        cout << "Password is wrong" << endl;
        return false;
    }


}

int ItalianChef::makepizza(int f, int w)
{
    cout << "Give flour: ";
    cin >> f;
    cout << "Give water: ";
    cin >> w;
    int pizza = min(f, w) / 5;
    cout << "Pizzas prepared: " << pizza << endl;
}
