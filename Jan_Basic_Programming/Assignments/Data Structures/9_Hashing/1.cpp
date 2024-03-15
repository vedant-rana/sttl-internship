#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    static const int tableSize = 10;
    vector<pair<int, string>> table[tableSize];

    int hashFunction(int key) {
        return key % tableSize;
    }

public:

    void insert(int key, const string& value) {
        int index = hashFunction(key);


        while (!table[index].empty() && table[index].back().first != key) {
            index = (index + 1) % tableSize;
        }


        if (table[index].empty() || table[index].back().first != key) {
            table[index].emplace_back(key, value);
        } else {
            table[index].back().second = value;  
        }
    }

    string get(int key) {
        int index = hashFunction(key);

        while (!table[index].empty() && table[index].back().first != key) {
            index = (index + 1) % tableSize;
        }

        if (!table[index].empty() && table[index].back().first == key) {
            return table[index].back().second;
        } else {
            return "";
        }
    }

    void remove(int key) {
        int index = hashFunction(key);

        while (!table[index].empty() && table[index].back().first != key) {
            index = (index + 1) % tableSize;
        }

        if (!table[index].empty() && table[index].back().first == key) {
            table[index].pop_back();
        }
    }

    void display() {
        for (int i = 0; i < tableSize; ++i) {
            cout << i << ": ";
            for (const auto& entry : table[i]) {
                cout << "(" << entry.first << ", " << entry.second << ") ";
            }
            cout << "\n";
        }
    }
};

int main() {
    HashTable myHashTable;

    myHashTable.insert(1, "One");
    myHashTable.insert(11, "Eleven");
    myHashTable.insert(21, "Twenty-One");
    myHashTable.insert(5, "Five");

    cout << "Initial Hash Table:\n";
    myHashTable.display();
    cout << "\n";

    cout << "Value for key 1: " << myHashTable.get(1) << "\n";
    cout << "Value for key 11: " << myHashTable.get(11) << "\n";
    cout << "Value for key 21: " << myHashTable.get(21) << "\n";
    cout << "Value for key 5: " << myHashTable.get(5) << "\n";
    cout << "Value for key 7: " << myHashTable.get(7) << " (not found)\n\n";

    myHashTable.remove(11);
    cout << "Hash Table after removing key 11:\n";
    myHashTable.display();

    return 0;
}
