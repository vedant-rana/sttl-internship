#include <iostream>
#include <cmath>
#include <vector>

class VanEmdeBoasTree {
private:
    int universeSize;
    int min, max;
    VanEmdeBoasTree* summary;
    std::vector<VanEmdeBoasTree*> clusters;

public:
    VanEmdeBoasTree(int size) : universeSize(size), min(-1), max(-1), summary(nullptr) {
        if (size > 2) {
            int highBits = std::ceil(std::sqrt(size));
            int lowBits = size / highBits;

            summary = new VanEmdeBoasTree(highBits);

            clusters.resize(highBits);
            for (int i = 0; i < highBits; ++i) {
                clusters[i] = new VanEmdeBoasTree(lowBits);
            }
        }
    }

    void insert(int key) {
        if (min == -1) {
            min = max = key;
        } else {
            if (key < min) {
                std::swap(key, min);
            }
            if (universeSize > 2) {
                int high = key / clusters.size();
                int low = key % clusters.size();
                if (clusters[high]->min == -1) {
                    summary->insert(high);
                    clusters[high]->min = clusters[high]->max = low;
                } else {
                    clusters[high]->insert(low);
                }
            }
            if (key > max) {
                max = key;
            }
        }
    }

    bool contains(int key) {
        if (key == min || key == max) {
            return true;
        } else if (universeSize <= 2) {
            return false;
        } else {
            return clusters[key / clusters.size()]->contains(key % clusters.size());
        }
    }
};

int main() {
    VanEmdeBoasTree vebTree(16);

    vebTree.insert(2);
    vebTree.insert(8);
    vebTree.insert(14);

    std::cout << "Does vEB tree contain 8? " << (vebTree.contains(8) ? "Yes" : "No") << std::endl;
    std::cout << "Does vEB tree contain 10? " << (vebTree.contains(10) ? "Yes" : "No") << std::endl;

    return 0;
}
