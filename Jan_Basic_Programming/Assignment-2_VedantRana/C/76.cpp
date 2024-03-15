#include <iostream>
#include <unordered_map>
#include <vector>

class SuffixTree
{
public:
    struct Node
    {
        int start;
        int *end;
        Node *sLink;
        std::unordered_map<char, Node *> children;

        Node(int start, int *end) : start(start), end(end), sLink(nullptr) {}
    };

    explicit SuffixTree(const std::string &input) : text(input)
    {
        root = new Node(-1, nullptr);
        activeNode = root;
        activeEdge = -1;
        activeLength = 0;
        remainingSuffixCount = 0;
        leafEnd = -1;
        splitEnd = nullptr;

        buildSuffixTree();
    }

    void print() const
    {
        print(root, 0);
    }

private:
    std::string text;
    Node *root;
    Node *activeNode;
    int activeEdge;
    int activeLength;
    int remainingSuffixCount;
    int leafEnd;
    Node *splitEnd;

    void buildSuffixTree()
    {
        for (int i = 0; i < text.length(); ++i)
        {
            extendSuffixTree(i);
        }
    }

    void extendSuffixTree(int index)
    {
        leafEnd = index;
        ++remainingSuffixCount;
        splitEnd = nullptr;

        while (remainingSuffixCount > 0)
        {
            if (activeLength == 0)
            {
                activeEdge = index;
            }

            auto it = activeNode->children.find(text[activeEdge]);

            if (it == activeNode->children.end())
            {
                activeNode->children[text[activeEdge]] = new Node(index, &leafEnd);

                if (splitEnd != nullptr)
                {
                    splitEnd->sLink = activeNode;
                    splitEnd = nullptr;
                }
            }
            else
            {
                Node *next = it->second;
                int edgeLength = *(next->end) - next->start + 1;

                if (activeLength >= edgeLength)
                {
                    activeEdge += edgeLength;
                    activeLength -= edgeLength;
                    activeNode = next;
                    continue;
                }

                if (text[next->start + activeLength] == text[index])
                {
                    if (splitEnd != nullptr && activeNode != root)
                    {
                        splitEnd->sLink = activeNode;
                        splitEnd = nullptr;
                    }

                    ++activeLength;
                    break;
                }

                int *splitEndPtr = new int(next->start + activeLength - 1);
                Node *splitNode = new Node(next->start, splitEndPtr);
                activeNode->children[text[activeEdge]] = splitNode;
                next->start += activeLength;
                splitNode->children[text[next->start]] = next;

                splitNode->children[text[index]] = new Node(index, &leafEnd);

                if (splitEnd != nullptr)
                {
                    splitEnd->sLink = splitNode;
                }

                splitEnd = splitNode;
            }

            --remainingSuffixCount;

            if (activeNode == root && activeLength > 0)
            {
                --activeLength;
                activeEdge = index - remainingSuffixCount + 1;
            }
            else if (activeNode != root)
            {
                activeNode = activeNode->sLink;
            }
        }
    }

    void print(Node *node, int level) const
    {
        if (node == nullptr)
        {
            return;
        }

        for (const auto &entry : node->children)
        {
            for (int i = 0; i < level; ++i)
            {
                std::cout << "  ";
            }

            std::cout << entry.first << std::endl;
            print(entry.second, level + 1);
        }
    }
};

int main()
{
    std::string text = "banana";
    SuffixTree suffixTree(text);
    suffixTree.print();

    return 0;
}
