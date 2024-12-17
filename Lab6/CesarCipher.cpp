#include "CesarCipher.h"
CesarCipher::CesarCipher(int shift)
{
	this->shift = shift;
}
std::string CesarCipher::Encrypt(const std::string& text)
{
	std::string result = "";
	for (char c : text)
		result += char(c + shift);
	return result;
}
std::string CesarCipher::Decrypt(const std::string& cipher)
{
	std::string result = "";
	for (char c : cipher)
		result += char(c - shift);
	return result;
}
