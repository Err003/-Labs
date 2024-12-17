#include "Cipher.h"
#pragma once
class CesarCipher : public Cipher
{
private:
	int shift;
public:
	CesarCipher(int shift);
	std::string Encrypt(const std::string& text) override;
	std::string Decrypt(const std::string& cipher) override;
	~CesarCipher() override {}
};