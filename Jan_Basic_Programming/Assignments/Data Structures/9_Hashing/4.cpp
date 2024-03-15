#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> findIntersection(const vector<int>& arr1, const vector<int>& arr2) {
    unordered_set<int> hashSet(arr1.begin(), arr1.end());
    vector<int> intersection;

    for (int num : arr2) {
        if (hashSet.find(num) != hashSet.end()) {
            intersection.push_back(num);
            hashSet.erase(num); 
        }
    }

    return intersection;
}

int main() {
    vector<int> array1 = {1, 2, 2, 1};
    vector<int> array2 = {2, 2};

    vector<int> result = findIntersection(array1, array2);

    cout << "Intersection of the two arrays: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
