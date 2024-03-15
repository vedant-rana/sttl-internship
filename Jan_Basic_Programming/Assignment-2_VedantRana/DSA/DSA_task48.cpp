#include <iostream>
#include <vector>
#include <algorithm>

class SuffixArray {
private:
    std::string text;
    std::vector<int> suffixArray;

public:
    SuffixArray(const std::string& inputText) : text(inputText) {
        constructSuffixArray();
    }

    const std::vector<int>& getSuffixArray() const {
        return suffixArray;
    }

private:
    void constructSuffixArray() {
        int n = text.length();
        std::vector<std::pair<std::string, int>> suffixes(n);

        
        for (int i = 0; i < n; i++) {
            suffixes[i] = {text.substr(i), i};
        }

        
        std::sort(suffixes.begin(), suffixes.end());

        
        suffixArray.resize(n);
        for (int i = 0; i < n; i++) {
            suffixArray[i] = suffixes[i].second;
        }
    }
};

int main() {
    std::string inputText = "banana";
    SuffixArray suffixArray(inputText);

    const std::vector<int>& result = suffixArray.getSuffixArray();

    std::cout << "Suffix Array for '" << inputText << "':\n";
    for (int index : result) {
        std::cout << index << " ";
    }

    return 0;
}
