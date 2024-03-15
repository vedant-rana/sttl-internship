#include <iostream>
#include <vector>

using namespace std;

class FractionalCascading {
public:
    FractionalCascading(const vector<vector<int>>& structures) {
        for (const auto& structure : structures) {
            structures_.emplace_back(structure);
        }
    }

    int binarySearch(int target) {
        return binarySearchHelper(0, 0, target);
    }

private:
    vector<vector<int>> structures_;

    int binarySearchHelper(int level, int index, int target) {
        if (level == structures_.size()) {
            return -1; 
        }

        const vector<int>& currentStructure = structures_[level];

        
        auto it = lower_bound(currentStructure.begin(), currentStructure.end(), target);

        
        if (it != currentStructure.end() && *it == target) {
            return *it;
        }

        
        int nextIndex = distance(currentStructure.begin(), it);
        int nextResult = binarySearchHelper(level + 1, index * 2 + nextIndex, target);

        if (nextResult != -1) {
            return nextResult;
        }

        
        return binarySearchHelper(level + 1, index * 2 + nextIndex + 1, target);
    }
};

int main() {
    
    vector<vector<int>> structures = {
        {1, 3, 5, 7, 9},
        {2, 4, 6, 8, 10},
        {11, 13, 15, 17, 19}
    };

    FractionalCascading fc(structures);

    int target = 8;
    int result = fc.binarySearch(target);

    if (result != -1) {
        cout << "Element " << target << " found in structure: " << result << endl;
    } else {
        cout << "Element " << target << " not found." << endl;
    }

    return 0;
}
