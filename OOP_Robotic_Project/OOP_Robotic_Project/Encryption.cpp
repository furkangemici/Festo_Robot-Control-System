#include "Encryption.h"
#include <utility>

int Encryption::encrypt(int code)
{
    int digits[4];
    for (int i = 3; i >= 0; --i)
    {
        digits[i] = (code % 10 + 7) % 10;
        code /= 10;
    }
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);

    int encryptedCode = 0;
    for (int i = 0; i < 4; ++i)
    {
        encryptedCode = encryptedCode * 10 + digits[i];
    }
    return encryptedCode;
}

int Encryption::decrypt(int code)
{
    int digits[4];
    for (int i = 3; i >= 0; --i)
    {
        digits[i] = code % 10;
        code /= 10;
    }
    std::swap(digits[0], digits[2]);
    std::swap(digits[1], digits[3]);

    int decryptedCode = 0;
    for (int i = 0; i < 4; ++i)
    {
        digits[i] = (digits[i] + 3) % 10; // Correct decryption adjustment
        decryptedCode = decryptedCode * 10 + digits[i];
    }
    return decryptedCode;
}
