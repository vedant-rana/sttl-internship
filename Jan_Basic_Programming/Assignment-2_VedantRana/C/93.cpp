#include <iostream>
#include <vector>
#include <string>
#include <functional>  // For std::hash

using namespace std;

class CarterWegmanHash {
private:
    vector<int> coefficients;
    int prime;

public:
    CarterWegmanHash(int size, int prime) : prime(prime) {
        coefficients.resize(size);

        // Initialize coefficients with random values
        for (int i = 0; i < size; ++i) {
            coefficients[i] = rand() % prime;
        }
    }

    // Hash a string
    int hash(const string& input) const {
        int result = 0;
        for (size_t i = 0; i < input.length(); ++i) {
            result = (result + coefficients[i % coefficients.size()] * input[i]) % prime;
        }
        return result;
    }
};

int main() {
    // Set the size of the coefficients vector and a prime number
    int coefficientSize = 3;
    int prime = 101;

    // Create a CarterWegmanHash object
    CarterWegmanHash hashFunction(coefficientSize, prime);

    // Test the hash function with some strings
    string input1 = "hello";
    string input2 = "world";

    int hashValue1 = hashFunction.hash(input1);
    int hashValue2 = hashFunction.hash(input2);

    cout << "Hash value for \"" << input1 << "\": " << hashValue1 << endl;
    cout << "Hash value for \"" << input2 << "\": " << hashValue2 << endl;

    return 0;
}
