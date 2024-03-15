#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class HuffmanNode {
public:
    char data;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
    
    static bool compare(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

class HuffmanCoding {
public:
    HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& frequencies) {
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, decltype(&HuffmanNode::compare)> minHeap(&HuffmanNode::compare);

        for (const auto& entry : frequencies) {
            minHeap.push(new HuffmanNode(entry.first, entry.second));
        }

        while (minHeap.size() > 1) {
            HuffmanNode* left = minHeap.top();
            minHeap.pop();

            HuffmanNode* right = minHeap.top();
            minHeap.pop();

            HuffmanNode* internalNode = new HuffmanNode('$', left->frequency + right->frequency);
            internalNode->left = left;
            internalNode->right = right;

            minHeap.push(internalNode);
        }

        return minHeap.top();
    }

    void generateHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
        if (root == nullptr) {
            return;
        }

        if (root->data != '$') {
            huffmanCodes[root->data] = code;
        }

        generateHuffmanCodes(root->left, code + "0", huffmanCodes);
        generateHuffmanCodes(root->right, code + "1", huffmanCodes);
    }

    string compressText(const string& text) {
        unordered_map<char, int> frequencies;
        for (char ch : text) {
            frequencies[ch]++;
        }

        HuffmanNode* root = buildHuffmanTree(frequencies);

        unordered_map<char, string> huffmanCodes;
        generateHuffmanCodes(root, "", huffmanCodes);

        string compressedText = "";
        for (char ch : text) {
            compressedText += huffmanCodes[ch];
        }

        return compressedText;
    }
};

int main() {
    HuffmanCoding huffman;

    string text = "hello world";
    string compressedText = huffman.compressText(text);

    cout << "Original Text: " << text << endl;
    cout << "Compressed Text: " << compressedText << endl;

    return 0;
}
