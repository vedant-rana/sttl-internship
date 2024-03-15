#include <iostream>
#include <vector>
#include <random>

using namespace std;

int getRandomElement(const vector<int>& reservoir) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(0, reservoir.size() - 1);
    return reservoir[distribution(gen)];
}

void reservoirSampling(const vector<int>& stream, int k) {
    vector<int> reservoir(k);

    
    for (int i = 0; i < k; ++i) {
        reservoir[i] = stream[i];
    }

    
    for (int i = k; i < stream.size(); ++i) {
        
        int j = getRandomElement(reservoir);

        
        if (j < k) {
            reservoir[j] = stream[i];
        }
    }

    
    cout << "Random Sample: ";
    for (int num : reservoir) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    
    vector<int> stream = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 3;

    reservoirSampling(stream, k);

    return 0;
}
