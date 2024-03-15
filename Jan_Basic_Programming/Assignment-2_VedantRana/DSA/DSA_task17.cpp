#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void generatePowerSet(string str) {
    size_t n = str.length();
    sort(str.begin(), str.end());

    vector<string> powerSet;
    for (size_t i = 0; i < (1 << n); ++i) {
        string subset;
        for (size_t j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subset += str[j];
            }
        }
        powerSet.push_back(subset);
    }

    sort(powerSet.begin(), powerSet.end());

    cout << "Power Set in Lexicographic Order:\n";
    for (const string& subset : powerSet) {
        cout << subset << " ";
    }
    cout << endl;
}

int main() {
    string input = "abc";
    generatePowerSet(input);

    return 0;
}
