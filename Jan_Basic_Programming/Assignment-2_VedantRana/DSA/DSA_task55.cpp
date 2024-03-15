#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct SuffixAutomatonNode {
    int length;
    int link;
    vector<int> next;

    SuffixAutomatonNode(int len = 0, int lnk = -1) : length(len), link(lnk) {
        next.clear();
    }
};

class SuffixAutomaton {
public:
    vector<SuffixAutomatonNode> nodes;
    int last;

    SuffixAutomaton(const string& str) {
        nodes.emplace_back();
        last = 0;

        for (char c : str) {
            extend(c, nodes);
        }
    }

    void extend(char c, vector<SuffixAutomatonNode>& nodes) {
        int newLast = nodes.size();
        nodes.emplace_back(nodes[last].length + 1);

        int p = last;
        while (p != -1 && !containsTransition(p, c, nodes)) {
            nodes[p].next.push_back(newLast);
            p = nodes[p].link;
        }

        if (p == -1) {
            nodes[newLast].link = 0;
        } else {
            int q = findTransition(p, c, nodes);
            if (nodes[p].length + 1 == nodes[q].length) {
                nodes[newLast].link = q;
            } else {
                int clone = nodes.size();
                nodes.emplace_back(nodes[q]);
                nodes[clone].length = nodes[p].length + 1;

                while (p != -1 && containsTransition(p, c, nodes) && findTransition(p, c, nodes) == q) {
                    nodes[p].next.pop_back();
                    nodes[p].next.push_back(clone);
                    p = nodes[p].link;
                }

                nodes[q].link = nodes[newLast].link = clone;
            }
        }

        last = newLast;
    }

    bool containsTransition(int p, char c, const vector<SuffixAutomatonNode>& nodes) const {
        for (int i : nodes[p].next) {
            if (nodes[i].length == nodes[p].length + 1 && str[i - nodes[i].length] == c) {
                return true;
            }
        }
        return false;
    }

    int findTransition(int p, char c, const vector<SuffixAutomatonNode>& nodes) const {
        for (int i : nodes[p].next) {
            if (nodes[i].length == nodes[p].length + 1 && str[i - nodes[i].length] == c) {
                return i;
            }
        }
        return -1;
    }

private:
    const string& str;
};

int main() {
    string text = "abab";
    SuffixAutomaton sa(text);

    // Access the suffix automaton nodes if needed
    // Example: Access the length of the first node
    int lengthOfFirstNode = sa.nodes[0].length;

    return 0;
}
