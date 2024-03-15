#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
using namespace std;
int main() {
    // Create a socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        cerr << "Error creating socket\n";
        return 1;
    }

    // Set up the server address structure
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(8080);

    // Bind the socket to the specified address and port
    if (bind(serverSocket, reinterpret_cast<sockaddr*>(&serverAddress), sizeof(serverAddress)) == -1) {
        cerr << "Error binding socket\n";
        close(serverSocket);
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        cerr << "Error listening for connections\n";
        close(serverSocket);
        return 1;
    }

    cout << "Server listening on port 8080...\n";

    // Accept a connection from a client
    int clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket == -1) {
        cerr << "Error accepting connection\n";
        close(serverSocket);
        return 1;
    }

    cout << "Client connected!\n";

    // Send a welcome message to the client
    const char* welcomeMessage = "Welcome to the server!";
    send(clientSocket, welcomeMessage, strlen(welcomeMessage), 0);

    // Close the sockets
    close(clientSocket);
    close(serverSocket);

    return 0;
}
