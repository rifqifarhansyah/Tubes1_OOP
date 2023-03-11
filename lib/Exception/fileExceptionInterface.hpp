#ifndef FILE_EXCEPTION_INTERFACE_HPP
#define FILE_EXCEPTION_INTERFACE_HPP

#include "exceptionInterface.hpp"
#include <string>

using namespace std;

class FileException : public Exception {
    protected:
        static int numOfFileException; // jumlah object FileException yang ada
        string path; // path dari file yang error
    
    public:
        // tidak memerlukan default ctor (tidak ada list of exception), assignment operator (tidak ada assignment), dan dtor (perlunya perhitungan jumlah object FileException setelah dihapus)
        FileException(string); // user-defined ctor
        FileException(const FileException&); // cctor

        string getFileException(); // path getter
        static int getNumOfFileException(); // numOfFileException getter
        void displayMessage() const; // message display
};

#endif