#include "lib/Game/Game.hpp"
#include <random>
#include <time.h>
int main(){
    srand(time(0));
    Game game;
    game.play();
}