#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct State {
    int length, link;
    unordered_map<char, int> transitions;

    State() : length(0), link(-1) {}
};

class SuffixAutomaton {
private:
    vector<State> states;
    int last;

public:
    SuffixAutomaton(const string& text) {
        states.push_back(State());
        last = 0;

        for (char c : text) {
            extendAutomaton(c);
        }

        
        states.push_back(State());
    }

    void extendAutomaton(char c) {
        int new_state = states.size();
        states.push_back(State());

        int current = last;
        states[new_state].length = states[current].length + 1;

        while (current != -1 && !states[current].transitions.count(c)) {
            states[current].transitions[c] = new_state;
            current = states[current].link;
        }

        if (current == -1) {
            states[new_state].link = 0;
        } else {
            int next = states[current].transitions[c];
            if (states[current].length + 1 == states[next].length) {
                states[new_state].link = next;
            } else {
                int clone = states.size();
                states.push_back(states[next]);
                states[clone].length = states[current].length + 1;

                while (current != -1 && states[current].transitions[c] == next) {
                    states[current].transitions[c] = clone;
                    current = states[current].link;
                }

                states[next].link = states[new_state].link = clone;
            }
        }

        last = new_state;
    }

    vector<int> findOccurrences(const string& pattern) {
        int currentState = 0;
        vector<int> occurrences;

        for (char c : pattern) {
            if (states[currentState].transitions.count(c)) {
                currentState = states[currentState].transitions[c];
            } else {
                currentState = -1;
                break;
            }
        }

        if (currentState != -1) {
            occurrences.push_back(states[currentState].length - pattern.size() + 1);
        }

        return occurrences;
    }
};

int main() {
    
    string text = "banana";
    string pattern = "ana";

    SuffixAutomaton automaton(text);
    vector<int> occurrences = automaton.findOccurrences(pattern);

    if (occurrences.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at positions: ";
        for (int pos : occurrences) {
            cout << pos << " ";
        }
        cout << endl;
    }

    return 0;
}
