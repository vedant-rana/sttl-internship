#include <iostream>
#include <unordered_map>
using namespace std;

char firstNonRepeatingCharacter(const string& str) {

    unordered_map<char, int> charFrequency;

    for (char ch : str) {
        charFrequency[ch]++;
    }

    for (char ch : str) {
        if (charFrequency[ch] == 1) {
            return ch; 
        }
    }

    return '\0'; 
}

int main() {
    string input = "programming";

    char result = firstNonRepeatingCharacter(input);

    if (result != '\0') {
        cout << "The first non-repeating character is: " << result << "\n";
    } else {
        cout << "No non-repeating character found in the string.\n";
    }

    return 0;
}
