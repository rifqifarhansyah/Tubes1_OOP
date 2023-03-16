#include "fileExceptionInterface.hpp"

#define RED "\033[1m\033[31m"
#define GREEN "\033[1m\033[32m"
#define YELLOW "\033[1m\033[33m"
#define BLUE "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN "\033[1m\033[36m"
#define RESET "\033[0m"


int FileException::numOfFileException = 0;

FileException::FileException(string _path) : Exception(ID) { // user-defined ctor
    path = _path;
    numOfFileException++;
}

FileException::FileException(const FileException& FE) : Exception(FE) { // cctor
    path = FE.path;
    numOfFileException++;
}

string FileException::getFileException(){ // path getter
    return path;
}

int FileException::getNumOfFileException() { // numOfFileException getter
    return numOfFileException;
}

void FileException::displayMessage() const { // message display
    cout << RED << "Path '" << path << "' tidak ditemukan." << RESET << endl;
}

// Path: Tubes1_OOP\lib\Exception\fileException.cpp
// Compare this snippet from Tubes1_OOP\lib\Exception\fileExceptionInterface.hpp: