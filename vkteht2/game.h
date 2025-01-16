#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;

class Game
{
public:
    Game(int maxNumber);
    ~Game();
    void play();

private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses = 0;
    void printGameResult();
};

#endif // GAME_H
