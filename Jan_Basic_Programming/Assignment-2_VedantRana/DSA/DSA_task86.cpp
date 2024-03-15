#include <iostream>
#include <unordered_map>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class TwoLevelTree {
private:
    TrieNode* root;

public:
    TwoLevelTree() : root(new TrieNode()) {}

    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current->isEndOfWord;
    }
};

int main() {
    TwoLevelTree twoLevelTree;

    twoLevelTree.insert("apple");
    twoLevelTree.insert("banana");

    std::cout << "Search 'apple': " << (twoLevelTree.search("apple") ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 'orange': " << (twoLevelTree.search("orange") ? "Found" : "Not Found") << std::endl;

    return 0;
}
