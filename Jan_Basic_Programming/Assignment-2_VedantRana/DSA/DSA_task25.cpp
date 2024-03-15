#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int selectRandomFromStream(int x, int& reservoir) {
    static int count = 0;
    count++;

    if (count == 1) {
        reservoir = x;
    } else {
        
        int randNum = rand() % count;

        
        if (randNum == 0) {
            reservoir = x;
        }
    }

    return reservoir;
}

int main() {
    
    srand(time(0));

    
    int stream[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    
    int reservoir = -1;
    for (int i = 0; i < sizeof(stream) / sizeof(stream[0]); ++i) {
        cout << "Random number from stream: " << selectRandomFromStream(stream[i], reservoir) << endl;
    }

    return 0;
}
