#include "DoubleCipher.h"
DoubleCipher::DoubleCipher(int cesarShift)
    : cesarCipher(cesarShift) {}

std::string DoubleCipher::Encrypt(const std::string& text)
{
    std::string cesarEncrypted = cesarCipher.Encrypt(text);
    std::string rowColumnEncrypted = rowColumnCipher.Encrypt(cesarEncrypted);
    return rowColumnEncrypted;
}

std::string DoubleCipher::Decrypt(const std::string& cipher)
{
    std::string rowColumnDecrypted = rowColumnCipher.Decrypt(cipher);
    std::string cesarDecrypted = cesarCipher.Decrypt(rowColumnDecrypted);
    return cesarDecrypted;
}