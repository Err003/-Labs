#include <iostream>

class GCDCalculator {
public:
    int findGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main() {
    GCDCalculator gcdCalc;
    int num1, num2;

    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    int gcd = gcdCalc.findGCD(num1, num2);

    std::cout << "The GCD is: " << gcd << std::endl;

    return 0;
}
