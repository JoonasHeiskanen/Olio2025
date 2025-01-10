#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int game(int maxnum);

int game(int maxnum){

    int random = rand() % (maxnum) + 1;
    int arvausStatus = 0;
    int arvaus;
    int arvaustenMaara = 0;
    int tila;

    while(arvausStatus == 0){
        cout << "Arvaa luku" << endl;
        cin >> arvaus;

        if(arvaus < random){
            cout << "Arvaus on liian pieni" << endl;
        }
        else if(arvaus > random){
            cout << "Arvaus on liian suuri" << endl;
        }
        else{
            cout << "Arvattu oikein" << endl;
            arvausStatus = 1;
        }
        arvaustenMaara++;
    }
    return arvaustenMaara;
}

int main()
{
    srand(time(NULL));
    int maxnum;
    cout << "Pelataan arvauspelia." << " Aseta maximi numero pelille" << endl;
    cin >> maxnum;
    int arvaustenMaara = game(maxnum);
    cout << "Arvasit " << arvaustenMaara << " kertaa" << endl;

    return 0;
}
