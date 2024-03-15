#include <iostream>
#include <vector>
#include <random>
#include <numeric>

using namespace std;

class ArbitraryRandomGenerator {
private:
    vector<int> values;
    vector<double> probabilities;
    uniform_real_distribution<double> distribution;
    mt19937 generator;

public:
    ArbitraryRandomGenerator(vector<int> inputValues, vector<double> inputProbabilities)
        : values(move(inputValues)), probabilities(move(inputProbabilities)), distribution(0.0, 1.0), generator(random_device{}()) {

        
        double sum = accumulate(probabilities.begin(), probabilities.end(), 0.0);
        for (double& prob : probabilities) {
            prob /= sum;
        }
    }

    int generateRandomNumber() {
        double randValue = distribution(generator);
        double cumulativeProb = 0.0;

        for (size_t i = 0; i < probabilities.size(); ++i) {
            cumulativeProb += probabilities[i];
            if (randValue <= cumulativeProb) {
                return values[i];
            }
        }

        
        cerr << "Error: Unable to generate a random number." << endl;
        return -1;
    }
};

int main() {
    
    vector<int> values = {1, 2, 3, 4};
    vector<double> probabilities = {0.1, 0.2, 0.5, 0.2};

    ArbitraryRandomGenerator randomGenerator(values, probabilities);

    
    cout << "Random Numbers Generated:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << randomGenerator.generateRandomNumber() << " ";
    }
    cout << endl;

    return 0;
}
