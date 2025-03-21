#include "record.h"
#include <iostream>




bool Record::openFile() {
    if (!file.is_open()) {
        file.open(fileName, std::ios::in | std::ios::out | std::ios::app);
    }
    return file.is_open();
}

bool Record::closeFile() {
    if (file.is_open()) {
        file.close();
        return true;
    }
    return false;
}

void Record::setFileName(const std::string& filename) {
    if (file.is_open()) {
        file.close();
    }
    fileName = filename;
}

std::string Record::readLine() {
    std::string line;
    if (file.is_open() && file.good()) {
        std::getline(file, line);
    }
    return line;
}

bool Record::writeLine(const std::string& line) {
    if (file.is_open() && file.good()) {
        file << line << std::endl;
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Record& record) {
    os << "File Name: " << record.fileName;
    return os;
}

std::istream& operator>>(std::istream& is, Record& record) {
    is >> record.fileName;
    return is;
}
