/**
 * @file Encryption.h
 * @Author Yakub Þiyar Demirbaþ
 * @date December, 2024
 * @brief Header file for the Encryption class.
 *
 * This file contains the declaration of the Encryption class,
 * which provides methods for encrypting and decrypting integer codes.
 */
#ifndef ENCRYPTION_H
#define ENCRYPTION_H

 //! A class for encryption and decryption.
  /*!
   This class provides static methods to perform basic encryption
   and decryption operations on integer codes.
  */
class Encryption
{
public:
    //! Encrypts the given code.
    /*!
     * This static method applies an encryption algorithm to the provided code.
     * @param code The integer code to be encrypted.
     * @return The encrypted integer code.
     */
    static int encrypt(int code);

    //! Decrypts the given code.
    /*!
     * This static method reverses the encryption algorithm and restores the original code.
     * @param code The integer code to be decrypted.
     * @return The decrypted integer code.
     */
    static int decrypt(int code);
};

#endif // ENCRYPTION_H
