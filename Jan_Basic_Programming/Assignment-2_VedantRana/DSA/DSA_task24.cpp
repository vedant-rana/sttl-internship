#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int random01() {
    
    return rand() % 2;
}

int random06() {
    
    
    int randNum = 0;
    for (int i = 0; i < 3; ++i) {
        randNum = (randNum << 1) | random01();
    }

    
    if (randNum > 6) {
        return random06();
    }

    return randNum;
}

int main() {
    
    srand(time(0));

    
    for (int i = 0; i < 10; ++i) {
        cout << random06() << " ";
    }

    return 0;
}
