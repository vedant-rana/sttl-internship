#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool wordBreakUtil(const string& str, const unordered_set<string>& wordSet, size_t start, vector<string>& result) {
    size_t n = str.length();

    if (start == n) {
        for (const string& word : result) {
            cout << word << " ";
        }
        cout << endl;
        return true;
    }

    for (size_t end = start + 1; end <= n; ++end) {
        string prefix = str.substr(start, end - start);

        if (wordSet.find(prefix) != wordSet.end()) {
            result.push_back(prefix);

            if (wordBreakUtil(str, wordSet, end, result)) {
                return true;
            }

            result.pop_back();
        }
    }

    return false;
}

void wordBreak(const string& str, const unordered_set<string>& wordSet) {
    vector<string> result;
    if (!wordBreakUtil(str, wordSet, 0, result)) {
        cout << "Word Break not possible.\n";
    }
}

int main() {
    string input1 = "ilikesamsungmobile";
    unordered_set<string> wordSet1 = {"i", "like", "sam", "sung", "mobile"};

    string input2 = "ilikeicecreamandmango";
    unordered_set<string> wordSet2 = {"i", "like", "ice", "cream", "and", "mango"};

    cout << "Word Break for input1:\n";
    wordBreak(input1, wordSet1);

    cout << "\nWord Break for input2:\n";
    wordBreak(input2, wordSet2);

    return 0;
}
