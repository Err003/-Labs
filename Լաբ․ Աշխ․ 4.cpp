#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TranspositionCipher {
private:
    int numCols;  

    
    vector<vector<char>> createGrid(const string& message, int& numRows) {
        numRows = (message.size() + numCols - 1) / numCols;  

        
        vector<vector<char>> grid(numRows, vector<char>(numCols, ' '));

        
        int idx = 0;
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols && idx < message.size(); col++) {
                grid[row][col] = message[idx++];
            }
        }
        return grid;
    }

public:
   
    TranspositionCipher(int columns) : numCols(columns) {}

    
    string encrypt(const string& message) {
        int numRows;
        vector<vector<char>> grid = createGrid(message, numRows);

        
        string encryptedMessage;
        for (int col = 0; col < numCols; col++) {
            for (int row = 0; row < numRows; row++) {
                if (grid[row][col] != ' ') {
                    encryptedMessage += grid[row][col];
                }
            }
        }
        return encryptedMessage;
    }

    
    string decrypt(const string& encryptedMessage) {
        int numRows;
        vector<vector<char>> grid = createGrid(encryptedMessage, numRows);

       
        int idx = 0;
        for (int col = 0; col < numCols; col++) {
            for (int row = 0; row < numRows && idx < encryptedMessage.size(); row++) {
                grid[row][col] = encryptedMessage[idx++];
            }
        }

        
        string decryptedMessage;
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (grid[row][col] != ' ') {
                    decryptedMessage += grid[row][col];
                }
            }
        }
        return decryptedMessage;
    }
};

int main() {
    string message;
    int numCols;

    cout << "Enter the message to encrypt: ";
    getline(cin, message);

    cout << "Enter the number of columns for the grid: ";
    cin >> numCols;

    
    TranspositionCipher cipher(numCols);

   
    string encryptedMessage = cipher.encrypt(message);
    cout << "Encrypted Message: " << encryptedMessage << endl;

    
    string decryptedMessage = cipher.decrypt(encryptedMessage);
    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}
