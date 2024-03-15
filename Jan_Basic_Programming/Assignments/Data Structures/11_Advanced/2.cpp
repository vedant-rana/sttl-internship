#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Suffix {
    int index;
    string suffix;
};

bool compareSuffix(const Suffix &a, const Suffix &b) {
    return a.suffix < b.suffix;
}

vector<int> buildSuffixArray(const string &text) {
    int n = text.length();
    vector<Suffix> suffixes(n);

    for (int i = 0; i < n; ++i) {
        suffixes[i].index = i;
        suffixes[i].suffix = text.substr(i);
    }

    sort(suffixes.begin(), suffixes.end(), compareSuffix);

    vector<int> suffixArray(n);
    for (int i = 0; i < n; ++i) {
        suffixArray[i] = suffixes[i].index;
    }

    return suffixArray;
}

int main() {
    string text = "banana";

    vector<int> suffixArray = buildSuffixArray(text);

    cout << "Suffix Array: ";
    for (int index : suffixArray) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
