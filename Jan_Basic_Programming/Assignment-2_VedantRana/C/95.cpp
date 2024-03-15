#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>

class Token
{
public:
    Token(const std::vector<int> &values) : values(values) {}

    const std::vector<int> &getValues() const
    {
        return values;
    }

private:
    std::vector<int> values;
};

class AlphaMemory
{
public:
    void addToken(std::shared_ptr<Token> token)
    {
        tokens.push_back(token);
    }

    const std::vector<std::shared_ptr<Token>> &getTokens() const
    {
        return tokens;
    }

private:
    std::vector<std::shared_ptr<Token>> tokens;
};

class BetaMemory
{
public:
    void addToken(std::shared_ptr<Token> token)
    {
        tokens.push_back(token);
    }

    const std::vector<std::shared_ptr<Token>> &getTokens() const
    {
        return tokens;
    }

private:
    std::vector<std::shared_ptr<Token>> tokens;
};

class AlphaNode
{
public:
    AlphaNode(int attribute) : attribute(attribute) {}

    void addToken(std::shared_ptr<Token> token)
    {
        if (token->getValues()[attribute] == value)
        {
            outputMemory->addToken(token);
        }
    }

    void setOutputMemory(std::shared_ptr<AlphaMemory> memory)
    {
        outputMemory = memory;
    }

private:
    int attribute;
    int value = 1;
    std::shared_ptr<AlphaMemory> outputMemory;
};

class JoinNode
{
public:
    JoinNode(std::shared_ptr<AlphaMemory> leftMemory, std::shared_ptr<AlphaMemory> rightMemory)
        : leftMemory(leftMemory), rightMemory(rightMemory) {}

    void evaluate()
    {
        const auto &leftTokens = leftMemory->getTokens();
        const auto &rightTokens = rightMemory->getTokens();

        for (const auto &leftToken : leftTokens)
        {
            for (const auto &rightToken : rightTokens)
            {

                if (leftToken->getValues()[0] == rightToken->getValues()[1])
                {
                    outputMemory->addToken(leftToken);
                    outputMemory->addToken(rightToken);
                }
            }
        }
    }

    void setOutputMemory(std::shared_ptr<BetaMemory> memory)
    {
        outputMemory = memory;
    }

private:
    std::shared_ptr<AlphaMemory> leftMemory;
    std::shared_ptr<AlphaMemory> rightMemory;
    std::shared_ptr<BetaMemory> outputMemory;
};

class ReteNetwork
{
public:
    void addAlphaNode(std::shared_ptr<AlphaNode> node)
    {
        alphaNodes.push_back(node);
    }

    void addJoinNode(std::shared_ptr<JoinNode> node)
    {
        joinNodes.push_back(node);
    }

    void propagateToken(std::shared_ptr<Token> token)
    {
        for (const auto &alphaNode : alphaNodes)
        {
            alphaNode->addToken(token);
        }

        for (const auto &joinNode : joinNodes)
        {
            joinNode->evaluate();
        }
    }

private:
    std::vector<std::shared_ptr<AlphaNode>> alphaNodes;
    std::vector<std::shared_ptr<JoinNode>> joinNodes;
};

int main()
{

    auto alphaMemory1 = std::make_shared<AlphaMemory>();
    auto alphaMemory2 = std::make_shared<AlphaMemory>();
    auto betaMemory = std::make_shared<BetaMemory>();

    auto alphaNode1 = std::make_shared<AlphaNode>(0);
    alphaNode1->setOutputMemory(alphaMemory1);

    auto alphaNode2 = std::make_shared<AlphaNode>(1);
    alphaNode2->setOutputMemory(alphaMemory2);

    auto joinNode = std::make_shared<JoinNode>(alphaMemory1, alphaMemory2);
    joinNode->setOutputMemory(betaMemory);

    ReteNetwork reteNetwork;
    reteNetwork.addAlphaNode(alphaNode1);
    reteNetwork.addAlphaNode(alphaNode2);
    reteNetwork.addJoinNode(joinNode);

    auto token = std::make_shared<Token>(std::vector<int>{1, 1});
    reteNetwork.propagateToken(token);

    const auto &resultTokens = betaMemory->getTokens();

    std::cout << "Result Tokens:" << std::endl;
    for (const auto &resultToken : resultTokens)
    {
        const auto &values = resultToken->getValues();
        std::cout << "[" << values[0] << ", " << values[1] << "]" << std::endl;
    }

    return 0;
}
