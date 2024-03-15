#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjacencyMatrix;

    Graph(int v) : vertices(v), adjacencyMatrix(v, vector<int>(v, 0)) {}

    void addEdge(int from, int to, int weight) {
        adjacencyMatrix[from][to] = weight;
        adjacencyMatrix[to][from] = weight;
    }
};

struct Individual {
    vector<int> chromosome;
    int fitness;

    Individual(int size) : chromosome(size), fitness(0) {}
};

const int POPULATION_SIZE = 50;
const int NUM_GENERATIONS = 100;
const double MUTATION_RATE = 0.1;

vector<Individual> initializePopulation(int chromosomeSize, int populationSize) {
    vector<Individual> population;

    for (int i = 0; i < populationSize; ++i) {
        Individual individual(chromosomeSize);

        for (int j = 0; j < chromosomeSize; ++j) {
            individual.chromosome[j] = rand() % 2;
        }

        population.push_back(individual);
    }

    return population;
}

int evaluateFitness(const Individual& individual, const Graph& graph) {
    int fitness = 0;

    // Your fitness evaluation logic here

    return fitness;
}

Individual crossover(const Individual& parent1, const Individual& parent2) {
    Individual child(parent1.chromosome.size());

    int crossoverPoint = rand() % parent1.chromosome.size();

    for (int i = 0; i < crossoverPoint; ++i) {
        child.chromosome[i] = parent1.chromosome[i];
    }

    for (int i = crossoverPoint; i < child.chromosome.size(); ++i) {
        child.chromosome[i] = parent2.chromosome[i];
    }

    return child;
}

void mutate(Individual& individual) {
    for (int i = 0; i < individual.chromosome.size(); ++i) {
        if ((rand() / (double)RAND_MAX) < MUTATION_RATE) {
            individual.chromosome[i] = 1 - individual.chromosome[i];
        }
    }
}

pair<Individual, Individual> selectParents(const vector<Individual>& population) {
    int index1 = rand() % population.size();
    int index2 = rand() % population.size();

    return make_pair(population[index1], population[index2]);
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Graph sampleGraph(5);
    sampleGraph.addEdge(0, 1, 2);
    sampleGraph.addEdge(1, 2, 3);
    sampleGraph.addEdge(2, 3, 1);
    sampleGraph.addEdge(3, 4, 4);
    sampleGraph.addEdge(4, 0, 5);

    vector<Individual> population = initializePopulation(sampleGraph.vertices, POPULATION_SIZE);

    for (int generation = 0; generation < NUM_GENERATIONS; ++generation) {
        for (auto& individual : population) {
            individual.fitness = evaluateFitness(individual, sampleGraph);
        }

        vector<Individual> newPopulation;

        for (int i = 0; i < POPULATION_SIZE; ++i) {
            auto parents = selectParents(population);
            Individual child = crossover(parents.first, parents.second);
            mutate(child);
            newPopulation.push_back(child);
        }

        population = newPopulation;
    }

    auto bestIndividual = max_element(population.begin(), population.end(),
        [](const Individual& ind1, const Individual& ind2) {
            return ind1.fitness < ind2.fitness;
        });

    cout << "Best Individual's Chromosome: ";
    for (int gene : bestIndividual->chromosome) {
        cout << gene << " ";
    }
    cout << "\nBest Individual's Fitness: " << bestIndividual->fitness << endl;

    return 0;
}
