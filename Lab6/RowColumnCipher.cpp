#include "RowColumnCipher.h"
char** RowColumCipher::FillSquareMatrix(const std::string& text, int& n)
{
    int len = text.size();
    n = ceil(sqrt(len));
    char** matrix = new char* [n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new char[n];
        for (int j = 0; j < n; ++j)
            matrix[i][j] = ' ';
    }
    int k = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (k < len)
                matrix[i][j] = text[k++];
    return matrix;
}
char** RowColumCipher::FillSquareMatrixDecryption(const std::string& text, int& n)
{
    int len = text.size();
    n = ceil(sqrt(len));
    char** matrix = new char* [n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new char[n];
        for (int j = 0; j < n; ++j)
            matrix[i][j] = ' ';
    }
    int k = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (k < len)
                matrix[j][i] = text[k++];
    return matrix;
}
char** RowColumCipher::TransposeMatrix(char** matrix, int n)
{
    char** transposed = new char* [n];
    for (int i = 0; i < n; ++i)
    {
        transposed[i] = new char[n];
        for (int j = 0; j < n; ++j)
            transposed[i][j] = matrix[j][i];
    }
    return transposed;
}
void RowColumCipher::FreeMatrix(char** matrix, int n)
{
    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;
}
RowColumCipher::RowColumCipher() {}
std::string RowColumCipher::Encrypt(const std::string& text)
{
    int n;
    char** matrix = FillSquareMatrix(text, n);
    char** transposed = TransposeMatrix(matrix, n);
    std::string encryptedText;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            encryptedText += transposed[i][j];
    FreeMatrix(matrix, n);
    FreeMatrix(transposed, n);
    return encryptedText;
}
std::string RowColumCipher::Decrypt(const std::string& ciphertext)
{
    int n;
    char** matrix = FillSquareMatrixDecryption(ciphertext, n);
    std::string decryptedText;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] != ' ')
                decryptedText += matrix[i][j];
    FreeMatrix(matrix, n);
    return
        decryptedText;
}
RowColumCipher::~RowColumCipher() {}