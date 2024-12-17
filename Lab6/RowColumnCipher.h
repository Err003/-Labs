#pragma once
#include "Cipher.h"
class RowColumCipher : public Cipher
{
private:
    char** FillSquareMatrix(const std::string& text, int& n);
    char** FillSquareMatrixDecryption(const std::string& text, int& n);
    char** TransposeMatrix(char** matrix, int n);
    void FreeMatrix(char** matrix, int n);
public:
    RowColumCipher();
    std::string Encrypt(const std::string& text) override;
    std::string Decrypt(const std::string& cipher) override;
    ~RowColumCipher() override;
};

