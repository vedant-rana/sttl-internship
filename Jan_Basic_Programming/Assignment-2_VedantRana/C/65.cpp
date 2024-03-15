#include <iostream>
#include <vector>
#include <random>
#include <cmath>
using namespace std;

double objectiveFunction(const vector<double> &x)
{

    double sum = 0.0;
    for (double value : x)
    {
        sum += value * value;
    }
    return sum;
}

void differentialEvolution(int populationSize, int dimensions, int maxGenerations, double scalingFactor, double crossoverRate)
{

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distribution(0.0, 1.0);

    vector<vector<double>> population(populationSize, vector<double>(dimensions));
    for (int i = 0; i < populationSize; ++i)
    {
        for (int j = 0; j < dimensions; ++j)
        {
            population[i][j] = distribution(gen);
        }
    }

    for (int generation = 0; generation < maxGenerations; ++generation)
    {
        for (int i = 0; i < populationSize; ++i)
        {

            int targetIndex = i;
            int donor1Index, donor2Index;
            do
            {
                donor1Index = distribution(gen) * populationSize;
            } while (donor1Index == i);
            do
            {
                donor2Index = distribution(gen) * populationSize;
            } while (donor2Index == i || donor2Index == donor1Index);

            vector<double> trialVector(dimensions);
            for (int j = 0; j < dimensions; ++j)
            {
                if (distribution(gen) < crossoverRate)
                {
                    trialVector[j] = population[donor1Index][j] + scalingFactor * (population[donor2Index][j] - population[i][j]);
                }
                else
                {
                    trialVector[j] = population[i][j];
                }
            }

            double targetFitness = objectiveFunction(population[targetIndex]);
            double trialFitness = objectiveFunction(trialVector);

            if (trialFitness < targetFitness)
            {
                population[targetIndex] = trialVector;
            }
        }
    }

    int bestIndex = 0;
    double bestFitness = objectiveFunction(population[0]);
    for (int i = 1; i < populationSize; ++i)
    {
        double currentFitness = objectiveFunction(population[i]);
        if (currentFitness < bestFitness)
        {
            bestFitness = currentFitness;
            bestIndex = i;
        }
    }

    cout << "Best solution found:" << endl;
    for (int j = 0; j < dimensions; ++j)
    {
        cout << "x[" << j << "] = " << population[bestIndex][j] << endl;
    }
    cout << "Objective value: " << bestFitness << endl;
}

int main()
{

    int populationSize = 50;
    int dimensions = 2;
    int maxGenerations = 100;
    double scalingFactor = 0.8;
    double crossoverRate = 0.9;

    differentialEvolution(populationSize, dimensions, maxGenerations, scalingFactor, crossoverRate);

    return 0;
}
