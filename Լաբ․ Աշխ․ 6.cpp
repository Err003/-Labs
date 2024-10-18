#include <iostream>
#include <vector>

int findMissingNumber(const std::vector<int>& numbers, int n) {
   
    int expectedSum = n * (n + 1) / 2;

    int actualSum = 0;
    for (int number : numbers) {
        actualSum += number;
    }

    
    return expectedSum - actualSum;
}

int main() {
    int n;
    std::cout << "Enter the upper limit: ";
    std::cin >> n;

    std::vector<int> numbers;
    std::cout << "Enter " << (n - 1) << " numbers in the interval (1 to " << n << "), separated by spaces:\n";
    
    for (int i = 0; i < n - 1; ) { 
        int number;
        std::cin >> number;

        
        if (number < 1 || number > n) {
            std::cout << "The number " << number << " doesn't belong to the interval. Please enter only numbers between 1 and " << n << ".\n";
        } else {
            numbers.push_back(number);
            i++; 
        }
    }

    int missingNumber = findMissingNumber(numbers, n);
    std::cout << "The missing number is: " << missingNumber << std::endl;

    return 0;
}
