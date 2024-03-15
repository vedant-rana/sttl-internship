package P52;

import java.util.Arrays;

// Quantum gate interface
interface QuantumGate {
    ComplexNumber[][] apply(ComplexNumber[][] input);
}

// Hadamard gate implementation
class HadamardGate implements QuantumGate {
    @Override
    public ComplexNumber[][] apply(ComplexNumber[][] input) {
        int size = input.length;
        double factor = 1.0 / Math.sqrt(size);

        ComplexNumber[][] result = new ComplexNumber[size][size];

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i][j] = input[i][j].multiply(factor);
            }
        }

        return result;
    }
}

// Quantum circuit class
class QuantumCircuit {
    private ComplexNumber[][] state;
    private QuantumGate[] gates;

    public QuantumCircuit(int numQubits) {
        int size = 1 << numQubits;  // Calculate 2^n for the state vector size
        state = new ComplexNumber[size][1];
        state[0][0] = new ComplexNumber(1, 0);  // Initialize with |0⟩ state

        gates = new QuantumGate[numQubits];
    }

    public void applyGate(int qubitIndex, QuantumGate gate) {
        gates[qubitIndex] = gate;
        updateState();
    }

    private void updateState() {
        for (QuantumGate gate : gates) {
            if (gate != null) {
                state = gate.apply(state);
            }
        }
    }

    public void printState() {
        System.out.println(Arrays.deepToString(state));
    }
}

// Complex number class for representing quantum amplitudes
class ComplexNumber {
    private double real;
    private double imaginary;

    public ComplexNumber(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    public ComplexNumber multiply(double scalar) {
        return new ComplexNumber(real * scalar, imaginary * scalar);
    }

    // Other operations can be added as needed

    @Override
    public String toString() {
        return "(" + real + ", " + imaginary + ")";
    }
}
public class TestQuantumComputing {
    public static void main(String[] args) {
        QuantumCircuit circuit = new QuantumCircuit(2);

        // Apply Hadamard gate on qubit 0
        circuit.applyGate(0, new HadamardGate());

        // Print the state after applying the gate
        System.out.println("State after Hadamard gate on qubit 0:");
        circuit.printState();
    }
}
