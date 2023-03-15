#include "../consoleIOInterface.hpp"
#include "../commandInterface.hpp"
#include "../consoleIO.cpp"
#include "../command.cpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    ConsoleIO CIO;
    int test = CIO.getIntInput();
    cout << test << endl;
    return 0;
}
