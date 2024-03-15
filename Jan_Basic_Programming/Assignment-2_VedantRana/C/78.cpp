#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

const int POPULATION_SIZE = 100;
const int MAX_GENERATIONS = 50;
const double MUTATION_RATE = 0.1;

// Define a node in the expression tree
struct Node {
    char op;  // Operator: '+', '-', '*', '/'
    double constant;  // Constant value if the node is a terminal
    Node* left;  // Left child
    Node* right; // Right child

    // Constructor for terminals
    Node(double value) : op('\0'), constant(value), left(nullptr), right(nullptr) {}

    // Constructor for operators
    Node(char operator_, Node* left_, Node* right_) : op(operator_), left(left_), right(right_), constant(0.0) {}

    // Destructor
    ~Node() {
        delete left;
        delete right;
    }
};

// Function to evaluate the expression tree for a given value of x
double evaluateExpression(Node* root, double x) {
    if (root->op == '\0') {
        return root->constant;  // Terminal node
    }

    double leftResult = evaluateExpression(root->left, x);
    double rightResult = evaluateExpression(root->right, x);

    switch (root->op) {
        case '+':
            return leftResult + rightResult;
        case '-':
            return leftResult - rightResult;
        case '*':
            return leftResult * rightResult;
        case '/':
            return rightResult != 0 ? leftResult / rightResult : 1.0;  // Avoid division by zero
        default:
            return 0.0;  // Invalid operator
    }
}

// Function to calculate the fitness of an individual based on how well it fits the target function
double calculateFitness(Node* root) {
    double fitness = 0.0;
    const double targetFunctionWeight = 1.0;

    for (double x = -10.0; x <= 10.0; x += 0.1) {
        double target = x * x + 3 * x + 5;
        double error = evaluateExpression(root, x) - target;
        fitness -= abs(error);
    }

    return fitness + targetFunctionWeight * abs(root->constant);  // Penalize constants
}

// Function to perform crossover between two parents to produce a child
Node* crossover(Node* parent1, Node* parent2) {
    // TODO: Implement crossover logic (not shown in this simple example)
    return nullptr;
}

// Function to perform mutation on an individual
void mutate(Node* root) {
    // TODO: Implement mutation logic (not shown in this simple example)
}

// Function to create a random expression tree
Node* createRandomExpression(int depth) {
    if (depth == 0 || (rand() % 2 == 0)) {
        // Terminal node (constant)
        return new Node(static_cast<double>(rand() % 10));
    } else {
        // Operator node
        char op;
        switch (rand() % 4) {
            case 0:
                op = '+';
                break;
            case 1:
                op = '-';
                break;
            case 2:
                op = '*';
                break;
            case 3:
                op = '/';
                break;
        }

        Node* left = createRandomExpression(depth - 1);
        Node* right = createRandomExpression(depth - 1);

        return new Node(op, left, right);
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    vector<Node*> population;

    // Initialize the population with random expression trees
    for (int i = 0; i < POPULATION_SIZE; ++i) {
        population.push_back(createRandomExpression(3));  // Initial depth is 3
    }

    for (int generation = 0; generation < MAX_GENERATIONS; ++generation) {
        // Evaluate fitness for each individual
        vector<pair<double, Node*>> fitnessList;
        for (Node* individual : population) {
            double fitness = calculateFitness(individual);
            fitnessList.emplace_back(fitness, individual);
        }

        // Sort individuals based on fitness
        sort(fitnessList.begin(), fitnessList.end(), greater<>());

        // Select the top individuals for crossover
        vector<Node*> selectedParents;
        for (int i = 0; i < POPULATION_SIZE / 2; ++i) {
            selectedParents.push_back(fitnessList[i].second);
        }

        // Create new population through crossover and mutation
        vector<Node*> newPopulation;
        for (int i = 0; i < POPULATION_SIZE; i += 2) {
            Node* parent1 = selectedParents[rand() % selectedParents.size()];
            Node* parent2 = selectedParents[rand() % selectedParents.size()];

            Node* child = crossover(parent1, parent2);
            mutate(child);

            newPopulation.push_back(child);
        }

        // Replace the old population with the new one
        for (Node* individual : population) {
            delete individual;
        }
        population = newPopulation;
    }

    // Print the best individual in the final generation
    double bestFitness = calculateFitness(population[0]);
    cout << "Best fitness: " << bestFitness << endl;

    // Clean up memory
    for (Node* individual : population) {
        delete individual;
    }

    return 0;
}
