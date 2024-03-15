#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    TrieNode* failureLink;
    vector<int> output;

    TrieNode() {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            children[i] = nullptr;
        }
        failureLink = nullptr;
    }
};

class AhoCorasick {
private:
    TrieNode* root;

    void buildTrie(const vector<string>& patterns) {
        root = new TrieNode();

        for (int patternIndex = 0; patternIndex < patterns.size(); ++patternIndex) {
            TrieNode* currentNode = root;

            for (char ch : patterns[patternIndex]) {
                int index = ch - 'a';

                if (currentNode->children[index] == nullptr) {
                    currentNode->children[index] = new TrieNode();
                }

                currentNode = currentNode->children[index];
            }

            currentNode->output.push_back(patternIndex);
        }
    }

    void buildFailureLinks() {
        queue<TrieNode*> q;
        root->failureLink = root;

        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (root->children[i] != nullptr) {
                root->children[i]->failureLink = root;
                q.push(root->children[i]);
            }
        }

        while (!q.empty()) {
            TrieNode* currentNode = q.front();
            q.pop();

            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                TrieNode* child = currentNode->children[i];

                if (child != nullptr) {
                    TrieNode* failureLinkNode = currentNode->failureLink;

                    while (failureLinkNode->children[i] == nullptr && failureLinkNode != root) {
                        failureLinkNode = failureLinkNode->failureLink;
                    }

                    if (failureLinkNode->children[i] != nullptr) {
                        child->failureLink = failureLinkNode->children[i];
                    } else {
                        child->failureLink = root;
                    }

                    q.push(child);
                }
            }
        }
    }

public:
    AhoCorasick(const vector<string>& patterns) {
        buildTrie(patterns);
        buildFailureLinks();
    }

    vector<int> search(const string& text) {
        vector<int> matches;
        TrieNode* currentNode = root;

        for (char ch : text) {
            int index = ch - 'a';

            while (currentNode->children[index] == nullptr && currentNode != root) {
                currentNode = currentNode->failureLink;
            }

            if (currentNode->children[index] != nullptr) {
                currentNode = currentNode->children[index];

                for (int patternIndex : currentNode->output) {
                    matches.push_back(patternIndex);
                }
            }
        }

        return matches;
    }
};

int main() {
    
    vector<string> patterns = {"he", "she", "his", "hers"};
    string text = "ushers";

    AhoCorasick ac(patterns);
    vector<int> matches = ac.search(text);

    cout << "String Matches at positions: ";
    for (int position : matches) {
        cout << position << " ";
    }
    cout << endl;

    return 0;
}
