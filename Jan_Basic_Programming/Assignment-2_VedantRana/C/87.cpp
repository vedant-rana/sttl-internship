#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <limits>

using namespace std;

// Structure to represent an instance (data point)
struct Instance {
    vector<double> features;
    string category;

    Instance(const vector<double>& feats, const string& cat) : features(feats), category(cat) {}
};

// Structure to represent a concept node in the COBWEB tree
struct ConceptNode {
    vector<double> mean; // Mean feature vector
    double numInstances; // Number of instances
    map<string, ConceptNode*> children; // Child nodes
};

// COBWEB Algorithm class
class COBWEB {
private:
    ConceptNode* root;

    // Function to calculate Euclidean distance between two feature vectors
    double calculateDistance(const vector<double>& v1, const vector<double>& v2) {
        double distance = 0.0;
        for (size_t i = 0; i < v1.size(); ++i) {
            distance += pow(v1[i] - v2[i], 2);
        }
        return sqrt(distance);
    }

    // Function to recursively insert an instance into the COBWEB tree
    void insertInstance(ConceptNode* node, const Instance& instance) {
        if (node->children.empty()) {
            // Leaf node, update the node's mean and count
            for (size_t i = 0; i < instance.features.size(); ++i) {
                node->mean[i] = (node->mean[i] * node->numInstances + instance.features[i]) / (node->numInstances + 1);
            }
            node->numInstances++;
        } else {
            // Find the closest child node
            double minDistance = numeric_limits<double>::max();
            ConceptNode* closestChild = nullptr;

            for (auto& [category, child] : node->children) {
                double distance = calculateDistance(instance.features, child->mean);
                if (distance < minDistance) {
                    minDistance = distance;
                    closestChild = child;
                }
            }

            // Recursively insert into the closest child
            insertInstance(closestChild, instance);
        }
    }

public:
    COBWEB() : root(new ConceptNode()) {}

    // Function to insert an instance into the COBWEB tree
    void insert(const Instance& instance) {
        insertInstance(root, instance);
    }

    // Function to print the COBWEB tree (in a simple textual format)
    void printTree(ConceptNode* node, int depth = 0) {
        if (!node) return;

        for (int i = 0; i < depth; ++i) {
            cout << "  ";
        }
        cout << "Category: " << (node->numInstances > 0 ? "Cluster" : "Leaf") << ", Mean: [";
        for (double mean : node->mean) {
            cout << mean << " ";
        }
        cout << "], Instances: " << node->numInstances << endl;

        for (auto& [category, child] : node->children) {
            printTree(child, depth + 1);
        }
    }

    // Function to print the entire COBWEB tree
    void printTree() {
        printTree(root);
    }
};

int main() {
    // Create a COBWEB instance
    COBWEB cobweb;

    // Insert some instances
    cobweb.insert(Instance({1.0, 2.0}, "A"));
    cobweb.insert(Instance({2.0, 3.0}, "B"));
    cobweb.insert(Instance({3.0, 4.0}, "A"));
    cobweb.insert(Instance({5.0, 6.0}, "B"));

    // Print the COBWEB tree
    cobweb.printTree();

    return 0;
}
