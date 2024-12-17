#include "DoubleCipher.h"
int main()
{
    std::string text;
    int cesarShift;
    std::cout<< "Enter text: ";
    std::cin >> text;
    std::cout<< "Enter cesar shift: ";
    std::cin >> cesarShift;
    DoubleCipher doubleCipher(cesarShift);

    std::string encryptedText = doubleCipher.Encrypt(text);
    std::cout << "Encrypted Text: " << encryptedText << std::endl;

    std::string decryptedText = doubleCipher.Decrypt(encryptedText);
    std::cout << "Decrypted Text: " << decryptedText << std::endl;

    return 0;
}