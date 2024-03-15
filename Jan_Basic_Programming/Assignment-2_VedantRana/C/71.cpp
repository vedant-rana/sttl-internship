#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

vector<int> compressLZW(const string &input)
{
    unordered_map<string, int> dictionary;
    int dictionarySize = 256;

    for (int i = 0; i < 256; ++i)
    {
        dictionary[string(1, static_cast<char>(i))] = i;
    }

    vector<int> result;
    string current;

    for (char c : input)
    {
        string currentPlusC = current + c;

        if (dictionary.find(currentPlusC) != dictionary.end())
        {
            current = currentPlusC;
        }
        else
        {

            result.push_back(dictionary[current]);
            dictionary[currentPlusC] = dictionarySize++;
            current = c;
        }
    }

    result.push_back(dictionary[current]);

    return result;
}

int main()
{

    string input = "ABABABABA";

    vector<int> compressedResult = compressLZW(input);

    cout << "Compressed result: ";
    for (int code : compressedResult)
    {
        cout << code << " ";
    }
    cout << endl;

    return 0;
}
