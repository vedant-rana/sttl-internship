#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie {
private:
    TrieNode* root;

    void insertWord(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    TrieNode* getNode(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return nullptr; 
            }
            current = current->children[ch];
        }
        return current;
    }

public:
    Trie() : root(new TrieNode()) {}

    void insert(const string& word) {
        insertWord(word);
    }

    bool search(const string& word) {
        TrieNode* node = getNode(word);
        return (node != nullptr) && (node->isEndOfWord);
    }

    TrieNode* getRoot() const {
        return root;
    }
};

class SpellChecker {
private:
    Trie dictionary;

    void suggestCorrectionsUtil(TrieNode* node, string currentWord, const string& targetWord, int distance, vector<string>& suggestions) {
        if (node == nullptr) {
            return;
        }

        if (node->isEndOfWord && distance <= 1) {
            suggestions.push_back(currentWord);
        }

        for (auto& child : node->children) {
            suggestCorrectionsUtil(child.second, currentWord + child.first, targetWord, distance + 1, suggestions);
            suggestCorrectionsUtil(child.second, currentWord + child.first, targetWord, distance, suggestions);
            suggestCorrectionsUtil(child.second, currentWord, targetWord, distance + 1, suggestions);
        }
    }

public:
    void addWordToDictionary(const string& word) {
        dictionary.insert(word);
    }

    bool checkSpelling(const string& word) {
        return dictionary.search(word);
    }

    vector<string> suggestCorrections(const string& word) {
        vector<string> suggestions;
        TrieNode* root = dictionary.getRoot();
        suggestCorrectionsUtil(root, "", word, 0, suggestions);
        return suggestions;
    }
};

int main() {
    SpellChecker spellChecker;

    spellChecker.addWordToDictionary("apple");
    spellChecker.addWordToDictionary("banana");
    spellChecker.addWordToDictionary("orange");
    spellChecker.addWordToDictionary("grape");
    spellChecker.addWordToDictionary("pear");

    string wordToCheck = "appl";
    bool isSpelledCorrectly = spellChecker.checkSpelling(wordToCheck);

    if (isSpelledCorrectly) {
        cout << "The word '" << wordToCheck << "' is spelled correctly.\n";
    } else {
        cout << "The word '" << wordToCheck << "' is misspelled.\n";

        vector<string> suggestions = spellChecker.suggestCorrections(wordToCheck);
        
        cout << "Suggestions for corrections:\n";
        for (const string& suggestion : suggestions) {
            cout << suggestion << "\n";
        }
    }

    return 0;
}
