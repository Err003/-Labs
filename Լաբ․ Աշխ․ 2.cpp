#include <iostream>
#include <string>

class TextModifier {
private:
    const std::string original = "abcdefghijklmnopqrstuvwxyz";
    const std::string substitute = "mnopqrstuvwxyzabcdefghijkl";

public:
    std::string modifyText(const std::string& inputText) {
        std::string modifiedText = "";

        for (char ch : inputText) {
            bool found = false;
            for (size_t i = 0; i < original.size(); ++i) {
                if (ch == original[i]) {
                    modifiedText += substitute[i];
                    found = true;
                    break;
                }
            }
            if (!found) {
                modifiedText += ch; // Keep the character if not found
            }
        }
        return modifiedText;
    }
};

int main() {
    TextModifier textModifier;
    std::string inputText;

    std::cout << "Enter your text (lowercase letters only): ";
    std::getline(std::cin, inputText);

    std::string modifiedText = textModifier.modifyText(inputText);

    std::cout << "Modified text: " << modifiedText << std::endl;

    return 0;
}
