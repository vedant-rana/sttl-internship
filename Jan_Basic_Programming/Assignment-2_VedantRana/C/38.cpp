#include <iostream>
#include <stack>
#include <unordered_set>

using namespace std;

struct Node
{
    int data;
    Node *forward;
    Node *backward;
    bool visited;

    Node(int value) : data(value), forward(nullptr), backward(nullptr), visited(false) {}
};

void schorrWaite(Node *root)
{
    stack<Node *> nodeStack;
    unordered_set<Node *> visitedNodes;

    nodeStack.push(root);

    while (!nodeStack.empty())
    {
        Node *current = nodeStack.top();
        nodeStack.pop();

        if (current != nullptr && !current->visited)
        {

            current->visited = true;

            cout << current->data << " ";

            nodeStack.push(current->backward);
            nodeStack.push(current->forward);

            visitedNodes.insert(current);
        }
        else if (current != nullptr)
        {

            if (visitedNodes.find(current->forward) == visitedNodes.end())
            {
                nodeStack.push(current->forward);
            }

            if (visitedNodes.find(current->backward) == visitedNodes.end())
            {
                nodeStack.push(current->backward);
            }
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->forward = new Node(2);
    root->forward->forward = new Node(3);
    root->forward->forward->forward = new Node(4);

    root->forward->backward = root;
    root->forward->forward->backward = root->forward;

    cout << "Traversed Nodes: ";
    schorrWaite(root);
    cout << endl;

    delete root->forward->forward->forward;
    delete root->forward->forward;
    delete root->forward;
    delete root;

    return 0;
}
