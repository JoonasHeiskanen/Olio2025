#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Game::Game(int maxNumber) : maxNumber(maxNumber){
    srand(time(NULL));
    randomNumber = rand() % (maxNumber) +1;
    cout << "GAME CONSTRUCTOR: ";
    cout << "Peli alustettu maximi arvolla " << maxNumber << endl;
}

Game::~Game(){
    cout << "GAME DESTRUCTOR: Pelasit pelin lapi" << endl;
}

void Game::play(){
    bool stayInLoop = true;
    cout << "Arvauspeli alkaa. Arvaa luku valilta 1-" << maxNumber << endl;
    while(stayInLoop){
        cout << "Arvaa luku" << endl;
        cin >> playerGuess;
        if(playerGuess > randomNumber){
            cout << "Arvaus on liian suuri" << endl;
        }
        else if(playerGuess < randomNumber){
            cout << "Arvaus liian pieni" << endl;
        }
        else{
            cout << "Arvasit oikein" << endl;
            stayInLoop = false;
        }
        numOfGuesses++;
    }
    printGameResult();
}

void Game::printGameResult(){
    cout << "Oikea numero on " << randomNumber << endl;
    cout << "Arvasit " << numOfGuesses << " kertaa" << endl;

}
