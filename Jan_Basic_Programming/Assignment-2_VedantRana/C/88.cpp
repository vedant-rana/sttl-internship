#include <iostream>
#include <stack>
#include <cctype>

struct TreeNode
{
    char data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

class ExpressionTreeBuilder
{
public:
    TreeNode *buildExpressionTree(const std::string &postfixExpression)
    {
        std::stack<TreeNode *> stack;

        for (char token : postfixExpression)
        {
            if (std::isalnum(token))
            {

                stack.push(new TreeNode(token));
            }
            else
            {

                TreeNode *rightOperand = stack.top();
                stack.pop();

                TreeNode *leftOperand = stack.top();
                stack.pop();

                TreeNode *operatorNode = new TreeNode(token);
                operatorNode->left = leftOperand;
                operatorNode->right = rightOperand;

                stack.push(operatorNode);
            }
        }

        return stack.top();
    }

    void inOrderTraversal(TreeNode *root)
    {
        if (root != nullptr)
        {
            inOrderTraversal(root->left);
            std::cout << root->data << " ";
            inOrderTraversal(root->right);
        }
    }

    void destroyExpressionTree(TreeNode *root)
    {
        if (root != nullptr)
        {
            destroyExpressionTree(root->left);
            destroyExpressionTree(root->right);
            delete root;
        }
    }
};

int main()
{

    std::string postfixExpression = "34+2*";

    ExpressionTreeBuilder treeBuilder;
    TreeNode *root = treeBuilder.buildExpressionTree(postfixExpression);

    std::cout << "In-order traversal of the expression tree: ";
    treeBuilder.inOrderTraversal(root);
    std::cout << std::endl;

    treeBuilder.destroyExpressionTree(root);

    return 0;
}
