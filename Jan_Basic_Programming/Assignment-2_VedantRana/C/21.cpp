#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string burrowsWheelerTransform(const string& input) {
    vector<string> rotations;
    string concatenated = input + "$";

    for (size_t i = 0; i < concatenated.size(); ++i) {
        rotations.push_back(concatenated.substr(i) + concatenated.substr(0, i));
    }

    sort(rotations.begin(), rotations.end());

    string result;
    for (const auto& rotation : rotations) {
        result += rotation.back();
    }

    return result;
}

int main() {
    string input;
    cin >> input;

    string bwtResult = burrowsWheelerTransform(input);

    cout << "Burrows-Wheeler Transform: " << bwtResult << endl;

    return 0;
}
