#pragma once
#include <iostream>
#include <string>
class Cipher
{
public:
    virtual std::string Encrypt(const std::string& text) = 0;
    virtual std::string Decrypt(const std::string& cipher) = 0;
    virtual ~Cipher() = 0;
};

