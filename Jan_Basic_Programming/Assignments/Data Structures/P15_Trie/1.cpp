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

    TrieNode* getNode(const string& prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (current->children.find(ch) == current->children.end()) {
                return nullptr;  // Prefix not found
            }
            current = current->children[ch];
        }
        return current;
    }

    void autocompleteUtil(TrieNode* node, string prefix, vector<string>& suggestions) {
        if (node->isEndOfWord) {
            suggestions.push_back(prefix);
        }

        for (auto& child : node->children) {
            autocompleteUtil(child.second, prefix + child.first, suggestions);
        }
    }

public:
    Trie() : root(new TrieNode()) {}

    void insert(const string& word) {
        insertWord(word);
    }

    vector<string> autocomplete(const string& prefix) {
        TrieNode* node = getNode(prefix);
        vector<string> suggestions;

        if (node) {
            autocompleteUtil(node, prefix, suggestions);
        }

        return suggestions;
    }
};

int main() {
    Trie trie;


    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");
    trie.insert("banana");
    trie.insert("bat");
    trie.insert("batman");


    string prefix = "app";
    vector<string> suggestions = trie.autocomplete(prefix);

    cout << "Autocomplete suggestions for prefix '" << prefix << "':\n";
    for (const string& suggestion : suggestions) {
        cout << suggestion << "\n";
    }

    return 0;
}
