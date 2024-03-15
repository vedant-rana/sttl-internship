#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;

int main() {
    string userInput;

    while (true) {

        cout << "SimpleShell> ";

        getline(cin, userInput);

        if (userInput == "exit") {
            break;
        }
        // system is a C++ standard library function that allows you to run shell commands.
        int exitCode = system(userInput.c_str());

        cout << "Command returned: " << exitCode << endl;
    }

    return 0;
}
