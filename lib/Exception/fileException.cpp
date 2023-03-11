#include "fileExceptionInterface.hpp"

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
    cout << "Path '" << path << "' tidak ditemukan." << endl;
}

// Path: Tubes1_OOP\lib\Exception\fileException.cpp
// Compare this snippet from Tubes1_OOP\lib\Exception\fileExceptionInterface.hpp: