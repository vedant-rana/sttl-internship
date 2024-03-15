#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <cassert>

using namespace std;

const int BLOCK_SIZE = 1000;  

void burstSort(string inputFileName, string outputFileName) {
    ifstream inputFile(inputFileName, ios::binary);
    assert(inputFile.is_open());

    
    vector<int> block(BLOCK_SIZE);
    int blockNumber = 0;

    while (!inputFile.eof()) {
        inputFile.read(reinterpret_cast<char*>(block.data()), block.size() * sizeof(int));
        int elementsRead = inputFile.gcount() / sizeof(int);
        block.resize(elementsRead);

        
        sort(block.begin(), block.end());

        
        ofstream tempFile(to_string(blockNumber) + "_temp.dat", ios::binary);
        assert(tempFile.is_open());
        tempFile.write(reinterpret_cast<const char*>(block.data()), block.size() * sizeof(int));
        tempFile.close();

        blockNumber++;
    }

    inputFile.close();

    
    vector<ifstream> tempFiles(blockNumber);
    for (int i = 0; i < blockNumber; ++i) {
        tempFiles[i].open(to_string(i) + "_temp.dat", ios::binary);
        assert(tempFiles[i].is_open());
    }

    ofstream outputFile(outputFileName, ios::binary);
    assert(outputFile.is_open());

    vector<int> minValues(blockNumber);

    while (true) {
        
        for (int i = 0; i < blockNumber; ++i) {
            if (tempFiles[i].read(reinterpret_cast<char*>(&minValues[i]), sizeof(int))) {
                
            } else {
                
                minValues[i] = numeric_limits<int>::max();
            }
        }

        
        auto minValIter = min_element(minValues.begin(), minValues.end());
        if (*minValIter == numeric_limits<int>::max()) {
            break;
        }

        
        outputFile.write(reinterpret_cast<const char*>(&(*minValIter)), sizeof(int));

        
        int minIndex = distance(minValues.begin(), minValIter);
        assert(tempFiles[minIndex].read(reinterpret_cast<char*>(&minValues[minIndex]), sizeof(int)));
    }

    
    for (int i = 0; i < blockNumber; ++i) {
        tempFiles[i].close();
        remove((to_string(i) + "_temp.dat").c_str());
    }

    outputFile.close();
}

int main() {
    
    ofstream inputFile("input.dat", ios::binary);
    assert(inputFile.is_open());

    vector<int> randomIntegers = {5, 8, 2, 15, 10, 3, 7, 1, 12, 6};
    inputFile.write(reinterpret_cast<const char*>(randomIntegers.data()), randomIntegers.size() * sizeof(int));
    inputFile.close();

    
    burstSort("input.dat", "output.dat");

    
    ifstream outputFile("output.dat", ios::binary);
    assert(outputFile.is_open());

    vector<int> sortedOutput((istreambuf_iterator<char>(outputFile)),
                             istreambuf_iterator<char>());

    cout << "Sorted Output: ";
    for (int value : sortedOutput) {
        cout << value << " ";
    }
    cout << endl;

    outputFile.close();

    return 0;
}
