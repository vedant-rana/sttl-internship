#include <iostream>
#include <unordered_map>

using namespace std;

class SuffixTreeNode {
public:
    unordered_map<char, SuffixTreeNode*> children;
    int start;
    int* end;

    SuffixTreeNode(int start, int* end) : start(start), end(end) {}
};

class SuffixTree {
private:
    string text;
    SuffixTreeNode* root;

    SuffixTreeNode* newNode(int start, int* end) {
        return new SuffixTreeNode(start, end);
    }

    void printEdges(SuffixTreeNode* node, const string& originalText) {
        if (node == nullptr) {
            return;
        }

        for (auto it : node->children) {
            SuffixTreeNode* child = it.second;
            cout << originalText.substr(child->start, *child->end - child->start + 1) << endl;
            printEdges(child, originalText);
        }
    }

public:
    SuffixTree(const string& text) : text(text) {
        root = newNode(-1, new int(-1));

        for (int i = 0; i < text.length(); i++) {
            SuffixTreeNode* current = root;

            for (int j = i; j < text.length(); j++) {
                char ch = text[j];

                if (current->children.find(ch) == current->children.end()) {
                    current->children[ch] = newNode(j, new int(text.length() - 1));
                }

                current = current->children[ch];
            }
        }
    }

    void printSuffixTree() {
        cout << "Suffix Tree:\n";
        printEdges(root, text);
    }
};

int main() {
    string text = "banana";

    SuffixTree suffixTree(text);

    suffixTree.printSuffixTree();

    return 0;
}
