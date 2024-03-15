#include <iostream>
#include <list>

using namespace std;

int josephus(int n, int k) {
    list<int> people;

    
    for (int i = 1; i <= n; i++) {
        people.push_back(i);
    }

    auto it = people.begin();

    while (people.size() > 1) {
        for (int count = 1; count < k; count++) {
            it++;
            if (it == people.end()) {
                it = people.begin();  
            }
        }

        it = people.erase(it);

        if (it == people.end()) {
            it = people.begin();  
        }
    }

    return people.front();
}

int main() {
    int n, k;

    cout << "Enter the number of people (N): ";
    cin >> n;
    cout << "Enter the elimination position (K): ";
    cin >> k;

    int survivor = josephus(n, k);

    cout << "The survivor's position is: " << survivor << endl;

    return 0;
}
