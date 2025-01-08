#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--;  // Decrement to handle 1-based indexing
            char letter = 'A' + (columnNumber % 26);  // Get the current letter
            result = letter + result;  // Add to the front of the result string
            columnNumber /= 26;  // Move to the next digit
        }
        return result;
    }
};

int main() {
    Solution solution;
    int columnNumber = 2800;  // Example input
    cout << "Column title for " << columnNumber << " is: " << solution.convertToTitle(columnNumber) << endl;
    return 0;
}
