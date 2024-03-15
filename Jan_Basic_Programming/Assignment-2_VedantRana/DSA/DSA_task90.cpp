#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class SuffixTreeNode {
public:
    unordered_map<char, SuffixTreeNode*> children;
    SuffixTreeNode* suffixLink;
    int start;
    int* end; 

    SuffixTreeNode(int start, int* end) : start(start), end(end), suffixLink(nullptr) {}

    bool contains(char ch, int position) {
        if (start <= position && position < *end) {
            return children.find(ch) != children.end();
        }
        return false;
    }

    SuffixTreeNode* getChild(char ch) {
        return children[ch];
    }

    void addChild(char ch, SuffixTreeNode* child) {
        children[ch] = child;
    }
};

class SuffixTree {
private:
    string input;
    SuffixTreeNode* root;
    SuffixTreeNode* activeNode;
    int activeEdge;
    int activeLength;
    int remainingSuffixCount;

    
    int* end;

    
    SuffixTreeNode* createNewNode(int start, int* end) {
        return new SuffixTreeNode(start, end);
    }

    
    void extendSuffixTree(int position) {
        *end = position + 1;
        remainingSuffixCount++;

        SuffixTreeNode* lastCreatedNode = nullptr;

        while (remainingSuffixCount > 0) {
            if (activeLength == 0) {
                activeEdge = position;
            }

            char activeEdgeChar = input[activeEdge];

            if (!activeNode->contains(activeEdgeChar, position)) {
                SuffixTreeNode* newNode = createNewNode(position, end);
                activeNode->addChild(activeEdgeChar, newNode);

                if (lastCreatedNode != nullptr) {
                    lastCreatedNode->suffixLink = activeNode;
                    lastCreatedNode = nullptr;
                }
            } else {
                SuffixTreeNode* nextNode = activeNode->getChild(activeEdgeChar);

                int length = nextNode->start + activeLength - 1;
                if (position <= length) {
                    activeLength++;
                    break;
                }

                activeEdge += length + 1 - activeNode->start;
                activeLength--;
                activeNode = nextNode;
                continue;
            }

            remainingSuffixCount--;

            if (activeNode == root && activeLength > 0) {
                activeLength--;
                activeEdge = position - remainingSuffixCount + 1;
            } else if (activeNode->suffixLink != nullptr) {
                activeNode = activeNode->suffixLink;
            } else {
                activeNode = root;
            }
        }
    }

public:
    SuffixTree(const string& input) : input(input), root(nullptr), activeNode(nullptr),
                                      activeEdge(-1), activeLength(0), remainingSuffixCount(0),
                                      end(nullptr) {
        end = new int;
        *end = 0;
        buildSuffixTree();
    }

    ~SuffixTree() {
        delete end;
        deleteSuffixTree(root);
    }

    void buildSuffixTree() {
        root = createNewNode(-1, end);
        activeNode = root;

        for (int i = 0; i < input.length(); ++i) {
            extendSuffixTree(i);
        }
    }

    void deleteSuffixTree(SuffixTreeNode* node) {
        if (node == nullptr) {
            return;
        }

        for (auto& entry : node->children) {
            deleteSuffixTree(entry.second);
        }

        delete node;
    }
};

int main() {
    string input = "banana";
    SuffixTree suffixTree(input);
    

    return 0;
}
