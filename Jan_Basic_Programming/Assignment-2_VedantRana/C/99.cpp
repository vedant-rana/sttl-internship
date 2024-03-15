#include <iostream>
#include <vector>
#include <cmath>

class HiddenMarkovModel
{
public:
    HiddenMarkovModel(const std::vector<double> &initialProbabilities,
                      const std::vector<std::vector<double>> &transitionMatrix,
                      const std::vector<std::vector<double>> &emissionMatrix)
        : initialProbabilities(initialProbabilities),
          transitionMatrix(transitionMatrix),
          emissionMatrix(emissionMatrix),
          numStates(initialProbabilities.size()),
          numObservations(emissionMatrix[0].size()) {}

    std::vector<int> viterbi(const std::vector<int> &observations) const
    {
        std::vector<std::vector<double>> viterbiTable(numStates, std::vector<double>(observations.size()));
        std::vector<std::vector<int>> backpointer(numStates, std::vector<int>(observations.size(), -1));

        for (int state = 0; state < numStates; ++state)
        {
            viterbiTable[state][0] = initialProbabilities[state] * emissionMatrix[state][observations[0]];
        }

        for (int t = 1; t < observations.size(); ++t)
        {
            for (int currentState = 0; currentState < numStates; ++currentState)
            {
                double maxProbability = 0.0;
                int bestPrevState = -1;

                for (int prevState = 0; prevState < numStates; ++prevState)
                {
                    double transitionProbability = transitionMatrix[prevState][currentState];
                    double observationProbability = emissionMatrix[currentState][observations[t]];
                    double probability = viterbiTable[prevState][t - 1] * transitionProbability * observationProbability;

                    if (probability > maxProbability)
                    {
                        maxProbability = probability;
                        bestPrevState = prevState;
                    }
                }

                viterbiTable[currentState][t] = maxProbability;
                backpointer[currentState][t] = bestPrevState;
            }
        }

        double maxProbability = 0.0;
        int bestFinalState = -1;

        for (int state = 0; state < numStates; ++state)
        {
            if (viterbiTable[state][observations.size() - 1] > maxProbability)
            {
                maxProbability = viterbiTable[state][observations.size() - 1];
                bestFinalState = state;
            }
        }

        std::vector<int> bestPath(observations.size());
        bestPath[observations.size() - 1] = bestFinalState;

        for (int t = observations.size() - 2; t >= 0; --t)
        {
            bestPath[t] = backpointer[bestPath[t + 1]][t + 1];
        }

        return bestPath;
    }

private:
    std::vector<double> initialProbabilities;
    std::vector<std::vector<double>> transitionMatrix;
    std::vector<std::vector<double>> emissionMatrix;
    int numStates;
    int numObservations;
};

int main()
{

    std::vector<double> initialProbabilities = {0.6, 0.4};
    std::vector<std::vector<double>> transitionMatrix = {{0.7, 0.3}, {0.4, 0.6}};
    std::vector<std::vector<double>> emissionMatrix = {{0.5, 0.4, 0.1}, {0.1, 0.3, 0.6}};

    HiddenMarkovModel hmm(initialProbabilities, transitionMatrix, emissionMatrix);

    std::vector<int> observations = {0, 1, 2};

    std::vector<int> bestPath = hmm.viterbi(observations);

    std::cout << "Best Path: ";
    for (int state : bestPath)
    {
        std::cout << state << " ";
    }
    std::cout << std::endl;

    return 0;
}
