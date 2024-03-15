#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class AnagramFinder {
private:
    unordered_map<string, vector<string>> anagramMap;

    string sortString(const string& str) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        return sortedStr;
    }

public:
    void addWord(const string& word) {
        string sortedWord = sortString(word);
        anagramMap[sortedWord].push_back(word);
    }

    vector<string> findAnagrams(const string& inputWord) {
        string sortedInputWord = sortString(inputWord);
        return anagramMap[sortedInputWord];
    }
};

int main() {
    AnagramFinder anagramFinder;


    anagramFinder.addWord("listen");
    anagramFinder.addWord("silent");
    anagramFinder.addWord("enlist");
    anagramFinder.addWord("hello");
    anagramFinder.addWord("world");
    anagramFinder.addWord("arm");
    anagramFinder.addWord("ram");


    string inputWord = "silent";
    vector<string> anagrams = anagramFinder.findAnagrams(inputWord);

    cout << "Anagrams of '" << inputWord << "':\n";
    for (const string& anagram : anagrams) {
        cout << anagram << "\n";
    }

    return 0;
}
