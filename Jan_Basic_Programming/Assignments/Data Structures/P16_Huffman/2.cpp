#include <iostream>
#include <unordered_map>

using namespace std;

class HuffmanNode {
public:
    char data;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data) : data(data), left(nullptr), right(nullptr) {}
};

class HuffmanDecoder {
public:
    string decodeMessage(const string& encodedMessage, HuffmanNode* root) {
        string decodedMessage = "";
        HuffmanNode* current = root;

        for (char bit : encodedMessage) {
            if (bit == '0') {
                current = current->left;
            } else {
                current = current->right;
            }

            if (current->left == nullptr && current->right == nullptr) {
                decodedMessage += current->data;
                current = root;
            }
        }

        return decodedMessage;
    }
};

int main() {
    HuffmanNode* root = new HuffmanNode('$');
    root->left = new HuffmanNode('e');
    root->right = new HuffmanNode('$');
    root->right->left = new HuffmanNode('h');
    root->right->right = new HuffmanNode('$');
    root->right->right->left = new HuffmanNode('l');
    root->right->right->right = new HuffmanNode('$');
    root->right->right->right->left = new HuffmanNode('o');

    HuffmanDecoder huffmanDecoder;

    string encodedMessage = "01001100100110011001011010";

    string decodedMessage = huffmanDecoder.decodeMessage(encodedMessage, root);

    cout << "Encoded Message: " << encodedMessage << endl;
    cout << "Decoded Message: " << decodedMessage << endl;

    delete root->left;
    delete root->right->left;
    delete root->right->right->left;
    delete root->right->right->right->left;
    delete root->right->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
