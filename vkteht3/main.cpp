#include <iostream>
#include "italianchef.h"
#include "chef.h"

using namespace std;

int main()
{
    Chef chef("Gordon Ramsay");

    chef.getName();

    int salads = chef.makeSalad(20);
    cout << "can make salads " << salads << " portions" << endl;

    int soups = chef.makeSoup(20);
    cout << "can make soup " << soups << " portions" << endl << endl;

    ItalianChef kokki("Mario");

    kokki.getName();

    salads = kokki.makeSalad(10);
    cout << "can make salad " << salads << " portions" << endl;

    soups = kokki.makeSoup(10);
    cout << "can make soup " << soups << " portions" << endl << endl;

    int flour = 0;
    int water = 0;
    string password;

    kokki.askSecret(password, flour, water);

    return 0;
}
