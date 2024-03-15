#include <iostream>
#include <cmath>
#include <complex>
#include <vector>

using namespace std;

// Define the state of the quantum walker
using QuantumState = vector<complex<double>>;

// Function to perform the quantum coin flip operation
void coinOperator(QuantumState& state) {
    for (complex<double>& amplitude : state) {
        amplitude = 1.0 / sqrt(2) * amplitude;
    }
}

// Function to perform the quantum shift operation
void shiftOperator(QuantumState& state) {
    QuantumState newState(state.size(), 0);

    for (size_t i = 0; i < state.size() - 1; ++i) {
        newState[i + 1] += 0.5 * state[i];
        newState[i] += 0.5 * state[i + 1];
    }

    state = newState;
}

// Function to perform a single step of the quantum walk
void quantumWalkStep(QuantumState& state) {
    coinOperator(state);
    shiftOperator(state);
}

// Function to print the state of the quantum walker
void printState(const QuantumState& state) {
    for (const auto& amplitude : state) {
        cout << "| " << amplitude << " |^2" << endl;
    }
}

int main() {
    // Number of nodes in the line graph
    const int numNodes = 5;

    // Initialize the quantum state
    QuantumState state(numNodes, 0);
    state[0] = 1.0;  // Initial state at node 0

    // Perform several steps of the quantum walk
    const int numSteps = 3;
    cout << "Initial state:" << endl;
    printState(state);

    for (int step = 0; step < numSteps; ++step) {
        cout << "\nAfter step " << step + 1 << ":" << endl;
        quantumWalkStep(state);
        printState(state);
    }

    return 0;
}
