#include <iostream>
#include <string>

class CaesarCipher {
private:
    int shift;

public:
  
    CaesarCipher(int shift) : shift(shift % 26) {}


    std::string encrypt(const std::string& text) {
        std::string encryptedText = "";
        for (char ch : text) {
            if (ch >= 'a' && ch <= 'z') {
                char encryptedChar = (ch - 'a' + shift) % 26 + 'a';
                encryptedText += encryptedChar;
            } else {
                encryptedText += ch;  
            }
        }
        return encryptedText;
    }

    
    std::string decrypt(const std::string& text) {
        std::string decryptedText = "";
        for (char ch : text) {
            if (ch >= 'a' && ch <= 'z') {
                char decryptedChar = (ch - 'a' - shift + 26) % 26 + 'a';
                decryptedText += decryptedChar;
            } else {
                decryptedText += ch;
            }
        }
        return decryptedText;
    }
};

int main() {
    int shift;
    std::cout << "Enter the shift value (0-25): ";
    std::cin >> shift;

    CaesarCipher cipher(shift);
    std::cin.ignore(); 

    std::string inputText;
    std::cout << "Enter the text to encrypt (lowercase letters only): ";
    std::getline(std::cin, inputText);

    std::string encryptedText = cipher.encrypt(inputText);
    std::cout << "Encrypted text: " << encryptedText << std::endl;

    std::string decryptedText = cipher.decrypt(encryptedText);
    std::cout << "Decrypted text: " << decryptedText << std::endl;

    return 0;
}
