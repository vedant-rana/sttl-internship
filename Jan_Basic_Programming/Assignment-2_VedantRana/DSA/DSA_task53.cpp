#include <iostream>
#include <vector>

using namespace std;

struct Node {
    Node *left, *right, *up, *down;
    int row, col;

    Node(int r, int c) : left(this), right(this), up(this), down(this), row(r), col(c) {}
};

class DancingLinks {
private:
    int numCols;
    Node* header;
    vector<Node*> columnHeaders;
    vector<vector<int>> solution;

    void cover(Node* col) {
        col->right->left = col->left;
        col->left->right = col->right;

        Node* i = col->down;
        while (i != col) {
            Node* j = i->right;
            while (j != i) {
                j->down->up = j->up;
                j->up->down = j->down;
                j->col->size--;
                j = j->right;
            }
            i = i->down;
        }
    }

    void uncover(Node* col) {
        Node* i = col->up;
        while (i != col) {
            Node* j = i->left;
            while (j != i) {
                j->col->size++;
                j->down->up = j;
                j->up->down = j;
                j = j->left;
            }
            i = i->up;
        }
        col->right->left = col;
        col->left->right = col;
    }

    bool search() {
        if (header->right == header) {
            vector<int> currentSolution;
            for (const auto& row : solution) {
                currentSolution.push_back(row[0]);
            }
            solution.push_back(currentSolution);
            return true;
        }

        Node* col = header->right;
        cover(col);

        Node* row = col->down;
        while (row != col) {
            solution.push_back({row->row});

            Node* j = row->right;
            while (j != row) {
                cover(j->col);
                j = j->right;
            }

            if (search()) {
                return true;
            }

            solution.pop_back();
            col = row->col;
            j = row->left;
            while (j != row) {
                uncover(j->col);
                j = j->left;
            }

            row = row->down;
        }

        uncover(col);
        return false;
    }

public:
    DancingLinks(int numRows, int numCols, const vector<vector<int>>& matrix) : numCols(numCols) {
        header = new Node(-1, -1);
        columnHeaders.resize(numCols + 1);

        for (int j = 1; j <= numCols; ++j) {
            Node* newNode = new Node(0, j);
            newNode->left = header->left;
            newNode->right = header;
            header->left->right = newNode;
            header->left = newNode;
            columnHeaders[j] = newNode;
        }

        for (int i = 0; i < numRows; ++i) {
            Node* prev = nullptr;
            Node* first = nullptr;
            for (int j = 0; j < numCols; ++j) {
                if (matrix[i][j] == 1) {
                    Node* colHeader = columnHeaders[j + 1];
                    Node* newNode = new Node(i + 1, j + 1);
                    newNode->up = colHeader->up;
                    newNode->down = colHeader;
                    colHeader->up->down = newNode;
                    colHeader->up = newNode;
                    colHeader->size++;

                    if (prev) {
                        prev->right = newNode;
                        newNode->left = prev;
                    } else {
                        first = newNode;
                    }

                    prev = newNode;
                }
            }

            if (prev) {
                prev->right = first;
                first->left = prev;
            }
        }
    }

    vector<vector<int>> solve() {
        solution.clear();
        search();
        return solution;
    }
};

int main() {
    // Example usage:
    int numRows = 4;
    int numCols = 7;
    vector<vector<int>> matrix = {
        {1, 0, 0, 1, 0, 0, 1},
        {1, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 1},
        {0, 1, 1, 0, 0, 1, 0}
    };

    DancingLinks dl(numRows, numCols, matrix);
    vector<vector<int>> result = dl.solve();

    // Output the result
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
