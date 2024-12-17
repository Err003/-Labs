#include "RowColumnCipher.h"
#include "CesarCipher.h"
#pragma once
class DoubleCipher : public Cipher
{
private:
    RowColumCipher rowColumnCipher;
    CesarCipher cesarCipher;

public:
    DoubleCipher(int cesarShift);
    std::string Encrypt(const std::string& text) override;
    std::string Decrypt(const std::string& cipher) override;
    ~DoubleCipher() override {}
};

