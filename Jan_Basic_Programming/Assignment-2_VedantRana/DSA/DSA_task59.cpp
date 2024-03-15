#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SparseTable {
private:
    vector<vector<int>> table;
    vector<int> log2;

public:
    SparseTable(const vector<int>& array) {
        int n = array.size();
        int logN = std::log2(n) + 1; 

        table.assign(logN, vector<int>(n));
        log2.resize(n + 1);

        
        for (int i = 2; i <= n; i++) {
            log2[i] = std::log2(i);
        }

        
        for (int i = 0; i < n; i++) {
            table[0][i] = array[i];
        }

        
        for (int k = 1; (1 << k) <= n; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                table[k][i] = min(table[k - 1][i], table[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    int query(int left, int right) {
        int k = std::log2(right - left + 1);
        return min(table[k][left], table[k][right - (1 << k) + 1]);
    }
};

int main() {
    
    vector<int> array = {2, 5, 1, 8, 3, 7, 4, 6};
    SparseTable sparseTable(array);

    
    cout << "Minimum in range [1, 5]: " << sparseTable.query(1, 5) << endl;
    cout << "Minimum in range [3, 7]: " << sparseTable.query(3, 7) << endl;
    cout << "Minimum in range [0, 3]: " << sparseTable.query(0, 3) << endl;

    return 0;
}
