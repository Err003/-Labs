#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

class RLE {
public:
    
    std::string encode(const std::string& input) {
        std::ostringstream encoded;
        int count = 1;

        for (size_t i = 0; i < input.length(); ++i) {
            if (i == input.length() - 1 || input[i] != input[i + 1]) {
                encoded << input[i] << static_cast<char>(count);
                count = 1; 
            } else {
                ++count; 
            }
        }

        return encoded.str();
    }

    std::string decode(const std::string& input) {
        std::ostringstream decoded;
        for (size_t i = 0; i < input.length(); ++i) {
            char ch = input[i];
            ++i;

            
            int count = static_cast<int>(input[i]); 
            decoded << std::string(count, ch);
        }

        return decoded.str();
    }
};

int main() {
    RLE rle;
    std::string input;

    std::cout << "Enter a string to encode: ";
    std::getline(std::cin, input);

    std::string encoded = rle.encode(input);
    std::cout << "Encoded string: " << encoded << std::endl;

    std::string decoded = rle.decode(encoded);
    std::cout << "Decoded string: " << decoded << std::endl;

    return 0;
}
