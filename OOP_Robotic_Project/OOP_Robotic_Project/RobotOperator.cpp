#include "RobotOperator.h"
#include <iostream>


RobotOperator::RobotOperator(const std::string& name, const std::string& surname, unsigned int accessCode)
    : name(name), surname(surname), accessState(false)
{
    this->accessCode = encryptCode(accessCode);
}


std::string RobotOperator::getName() const
{
    return name;
}


std::string RobotOperator::getSurname() const
{
    return surname;
}


bool RobotOperator::getAccessState() const
{
    return accessState;
}


int RobotOperator::encryptCode(int code)
{
    return Encryption::encrypt(code);
}


int RobotOperator::decryptCode(int code)
{
    return Encryption::decrypt(code);
}


bool RobotOperator::checkAccessCode(int code)
{
    accessState = (encryptCode(code) == accessCode);
    return accessState;
}


void RobotOperator::print() const
{
    std::cout << "Name: " << name << " " << surname << "\n"
        << "Access State: " << (accessState ? "Granted" : "Denied") << std::endl;
}
