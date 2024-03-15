#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> compressLZW(const std::string& input) {
    std::unordered_map<std::string, int> dictionary;
    std::vector<int> compressedResult;

    
    for (int i = 0; i < 256; ++i) {
        dictionary[std::string(1, char(i))] = i;
    }

    std::string current;
    for (char ch : input) {
        std::string combined = current + ch;
        if (dictionary.find(combined) != dictionary.end()) {
            current = combined;
        } else {
            compressedResult.push_back(dictionary[current]);
            dictionary[combined] = dictionary.size();
            current = std::string(1, ch);
        }
    }

    if (!current.empty()) {
        compressedResult.push_back(dictionary[current]);
    }

    return compressedResult;
}

int main() {
    std::string input = "ababababcabcabc";

    std::vector<int> compressedResult = compressLZW(input);

    std::cout << "Original String: " << input << std::endl;
    std::cout << "Compressed Result: ";
    for (int code : compressedResult) {
        std::cout << code << " ";
    }
    std::cout << std::endl;

    return 0;
}
