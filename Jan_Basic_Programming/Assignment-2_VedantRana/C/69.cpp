#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <cstdlib>

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

vector<double> hillClimbing(int dimensions, double stepSize, int maxIterations)
{
    vector<double> currentSolution(dimensions);
    vector<double> neighborSolution(dimensions);

    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < dimensions; ++i)
    {
        currentSolution[i] = static_cast<double>(rand()) / RAND_MAX;
    }

    for (int iteration = 0; iteration < maxIterations; ++iteration)
    {
        double currentObjective = objectiveFunction(currentSolution);

        for (int i = 0; i < dimensions; ++i)
        {
            neighborSolution = currentSolution;
            neighborSolution[i] += (static_cast<double>(rand()) / RAND_MAX - 0.5) * stepSize;

            double neighborObjective = objectiveFunction(neighborSolution);

            if (neighborObjective < currentObjective)
            {
                currentSolution = neighborSolution;
                currentObjective = neighborObjective;
            }
        }
    }

    return currentSolution;
}

int main()
{

    int dimensions = 3;
    double stepSize = 0.1;
    int maxIterations = 1000;

    vector<double> result = hillClimbing(dimensions, stepSize, maxIterations);

    cout << "Optimal solution found:" << endl;
    for (int i = 0; i < dimensions; ++i)
    {
        cout << "x[" << i << "] = " << result[i] << endl;
    }
    cout << "Objective value: " << objectiveFunction(result) << endl;

    return 0;
}
