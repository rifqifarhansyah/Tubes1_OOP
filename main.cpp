// #include "./lib/IO/consoleIOInterface.hpp"
// #include "./lib/IO/commandInterface.hpp"
#include "lib/IO/consoleIO.cpp"
#include "lib/IO/command.cpp"

using namespace std;

int main() {
    ConsoleIO CIO;

    CIO.start();
    return 0;
}