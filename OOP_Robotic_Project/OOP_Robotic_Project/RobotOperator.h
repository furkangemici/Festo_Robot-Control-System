/**
 * @file RobotOperator.h
 * @Author Yakub Þiyar Demirbaþ
 * @date December, 2024
 * @brief Header file for the RobotOperator class.
 *
 * This file contains the declaration of the RobotOperator class,
 * which manages an operator's information and access control using
 * encrypted access codes.
 */
#ifndef ROBOTOPERATOR_H
#define ROBOTOPERATOR_H

#include <string>
#include "Encryption.h"


 //! A class representing a robot operator.
 /*!
  This class stores information about a robot operator, such as name,
  surname, and access code. It provides methods for encrypting and
  decrypting access codes, validating access, and printing operator details.
 */
class RobotOperator
{
private:
    //! The name of the operator.
    std::string name = "cem";

    //! The surname of the operator.
    std::string surname = "avci";

    //! The access code for the operator.
    unsigned int accessCode;

    //! The access state of the operator.
    bool accessState;

public:
    //! Constructor to initialize a RobotOperator object.
    /*!
     * @param name The operator's name.
     * @param surname The operator's surname.
     * @param accessCode The operator's access code.
     */
    RobotOperator(const std::string& name, const std::string& surname, unsigned int accessCode);

    //! Gets the name of the operator.
    /*!
     * @return The name of the operator.
     */
    std::string getName() const;

    //! Gets the surname of the operator.
    /*!
     * @return The surname of the operator.
     */
    std::string getSurname() const;

    //! Gets the access state of the operator.
    /*!
     * @return The access state of the operator (true if access is granted, false otherwise).
     */
    bool getAccessState() const;

    //! Encrypts the given access code.
    /*!
     * This method uses the Encryption class to encrypt the provided code.
     * @param code The access code to encrypt.
     * @return The encrypted access code.
     */
    int encryptCode(int code);

    //! Decrypts the given access code.
    /*!
     * This method uses the Encryption class to decrypt the provided code.
     * @param code The encrypted access code to decrypt.
     * @return The decrypted access code.
     */
    int decryptCode(int code);

    //! Checks if the given code matches the operator's access code.
    /*!
     * This method compares the given code with the operator's stored access code
     * to determine if access should be granted.
     * @param code The access code to validate.
     * @return True if the codes match, false otherwise.
     */

    
    bool checkAccessCode(int code);

    //! Prints the operator's details.
    /*!
     * Displays the operator's name, surname, and access state.
     */
    void print() const;
};

#endif
