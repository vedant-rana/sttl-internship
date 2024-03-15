#include <iostream>
#include <unordered_map>

using namespace std;

const int ALPHABET_SIZE = 26;

struct RadixNode {
    bool isEnd;
    unordered_map<string, RadixNode*> children;

    RadixNode() : isEnd(false) {}
};

class RadixTree {
private:
    RadixNode* root;

public:
    RadixTree() : root(new RadixNode()) {}

    void insert(string word) {
        insertRecursive(root, word);
    }

    bool search(string word) {
        return searchRecursive(root, word);
    }

    void remove(string word) {
        removeRecursive(root, word);
    }

private:
    void insertRecursive(RadixNode* node, const string& word) {
        if (word.empty()) {
            node->isEnd = true;
            return;
        }

        for (const auto& entry : node->children) {
            const string& key = entry.first;
            RadixNode* child = entry.second;

            int commonPrefix = longestCommonPrefix(word, key);

            if (commonPrefix > 0) {
                
                RadixNode* newNode = new RadixNode();
                newNode->children[key.substr(commonPrefix)] = child;
                node->children.erase(key);
                node->children[word.substr(0, commonPrefix)] = newNode;

                
                insertRecursive(newNode, word.substr(commonPrefix));
                return;
            }
        }

        
        RadixNode* newChild = new RadixNode();
        node->children[word] = newChild;
        newChild->isEnd = true;
    }

    bool searchRecursive(RadixNode* node, const string& word) {
        if (word.empty()) {
            return node->isEnd;
        }

        for (const auto& entry : node->children) {
            const string& key = entry.first;
            RadixNode* child = entry.second;

            int commonPrefix = longestCommonPrefix(word, key);

            if (commonPrefix > 0) {
                if (commonPrefix == key.length()) {
                    return searchRecursive(child, word.substr(commonPrefix));
                } else if (commonPrefix < key.length()) {
                    return false;  
                }
            }
        }

        return false;
    }

    void removeRecursive(RadixNode* node, const string& word) {
        if (word.empty()) {
            node->isEnd = false;
            return;
        }

        for (auto it = node->children.begin(); it != node->children.end(); ++it) {
            const string& key = it->first;
            RadixNode* child = it->second;

            int commonPrefix = longestCommonPrefix(word, key);

            if (commonPrefix > 0) {
                if (commonPrefix == key.length()) {
                    removeRecursive(child, word.substr(commonPrefix));
                    if (!child->isEnd && child->children.empty()) {
                        
                        delete child;
                        node->children.erase(it);
                    }
                    return;
                } else if (commonPrefix < key.length()) {
                    return;  
                }
            }
        }
    }

    int longestCommonPrefix(const string& str1, const string& str2) {
        int minLength = min(str1.length(), str2.length());
        int commonPrefix = 0;

        for (int i = 0; i < minLength; ++i) {
            if (str1[i] == str2[i]) {
                commonPrefix++;
            } else {
                break;
            }
        }

        return commonPrefix;
    }
};

int main() {
    
    RadixTree radixTree;

    radixTree.insert("apple");
    radixTree.insert("app");
    radixTree.insert("apricot");
    radixTree.insert("banana");

    cout << "Search 'apple': " << (radixTree.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (radixTree.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'apricot': " << (radixTree.search("apricot") ? "Found" : "Not Found") << endl;
    cout << "Search 'banana': " << (radixTree.search("banana") ? "Found" : "Not Found") << endl;

    radixTree.remove("apple");

    cout << "Search 'apple' after removal: " << (radixTree.search("apple") ? "Found" : "Not Found") << endl;

    return 0;
}
