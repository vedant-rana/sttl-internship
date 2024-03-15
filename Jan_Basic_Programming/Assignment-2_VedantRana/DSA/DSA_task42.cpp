#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;


struct HuffmanNode {
    char data;
    int frequency;
    HuffmanNode *left, *right;

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};


struct CompareNodes {
    bool operator()(HuffmanNode* const& node1, HuffmanNode* const& node2) {
        return node1->frequency > node2->frequency;
    }
};

class HuffmanCoding {
private:
    unordered_map<char, string> encodingTable;
    unordered_map<string, char> decodingTable;

    HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& frequencyMap) {
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;

        
        for (const auto& entry : frequencyMap) {
            minHeap.push(new HuffmanNode(entry.first, entry.second));
        }

        
        while (minHeap.size() > 1) {
            HuffmanNode* left = minHeap.top();
            minHeap.pop();

            HuffmanNode* right = minHeap.top();
            minHeap.pop();

            HuffmanNode* mergedNode = new HuffmanNode('$', left->frequency + right->frequency);
            mergedNode->left = left;
            mergedNode->right = right;

            minHeap.push(mergedNode);
        }

        return minHeap.top();
    }

    void buildEncodingTable(HuffmanNode* root, string currentCode) {
        if (root == nullptr) {
            return;
        }

        if (root->data != '$') {
            encodingTable[root->data] = currentCode;
            decodingTable[currentCode] = root->data;
        }

        buildEncodingTable(root->left, currentCode + "0");
        buildEncodingTable(root->right, currentCode + "1");
    }

public:
    string compress(const string& input) {
        
        unordered_map<char, int> frequencyMap;
        for (char ch : input) {
            frequencyMap[ch]++;
        }

        
        HuffmanNode* root = buildHuffmanTree(frequencyMap);

        
        buildEncodingTable(root, "");

        
        string compressed;
        for (char ch : input) {
            compressed += encodingTable[ch];
        }

        return compressed;
    }

    string decompress(const string& compressed) {
        string decoded;
        string currentCode;

        
        for (char bit : compressed) {
            currentCode += bit;

            if (decodingTable.find(currentCode) != decodingTable.end()) {
                decoded += decodingTable[currentCode];
                currentCode.clear();
            }
        }

        return decoded;
    }
};

int main() {
    HuffmanCoding huffman;

    
    string input = "huffman coding example";
    cout << "Original Input: " << input << endl;

    string compressed = huffman.compress(input);
    cout << "Compressed: " << compressed << endl;

    string decompressed = huffman.decompress(compressed);
    cout << "Decompressed: " << decompressed << endl;

    return 0;
}
