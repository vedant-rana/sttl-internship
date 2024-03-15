#include <bits/stdc++.h>
using namespace std;

// Tower of hanoi

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, source, destination, auxiliary);
    cout << "Move disk " << n << " from " << source << " to " << auxiliary << endl;
    towerOfHanoi(n - 1, destination, auxiliary, source);
}

int main()
{
    int n;

    cout << "Enter number of Disk to transfer : ";
    cin >> n;
    cout << endl;

    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
