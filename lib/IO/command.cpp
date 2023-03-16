#include "commandInterface.hpp"
#include "../Game/Game.hpp"
#include "../Player/Player.hpp"

#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN "\033[1m\033[36m"
#define RESET "\033[0m"

using namespace std;

int Command::numOfCommands = 0;

Command::Command()
{
}

int Command::getNumofCommands()
{
    return numOfCommands;
}

void Command::NEXT()
{
    cout << "Giliran dilanjut ke pemain selanjutnya." << endl;
    numOfCommands++;
}

void Command::DOUBLE(Player& player, Game& game)
{
    cout << player.getNamePlayer() << " melakukan DOUBLE!\n";
    int point = game.getPoint();
    int newPoint = point*2;
    cout << "Poin hadiah naik dari " << point << " menjadi " << newPoint << "!\n";
    game.setPoint(newPoint);
    numOfCommands++;
}

void Command::HALF(Player& player, Game& game)
{
    cout << player.getNamePlayer() << " melakukan HALF!\n";
    int point = game.getPoint();
    int newPoint = point/2;
    if (newPoint != 0){
        cout << "Poin hadiah turun dari " << point << " menjadi " << newPoint << "!\n";
        game.setPoint(newPoint);
    } else {
        cout << "Sayangnya poin hadiah sudah bernilai 1. Poin hadiah tidak berubah.. Giliran dilanjut.!\n";
    }
    numOfCommands++;
}

void Command::INVALIDCOMMAND(string _command)
{
    throw CommandException(_command);
}

// Path: lib\IO\command.cpp
// Compare this snippet from lib\IO\CommandInterface.hpp: