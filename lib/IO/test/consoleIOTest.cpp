#include "../consoleIOInterface.hpp"
#include "../commandInterface.hpp"
#include "../consoleIO.cpp"
#include "../command.cpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    ConsoleIO CIO;
    CIO.start();
    return 0;
}
