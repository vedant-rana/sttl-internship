#include <iostream>
#include <string>
using namespace std;

string encrypt(const string &message, int shift)
{
    string result = "";

    for (char ch : message)
    {
        if (isalpha(ch))
        {
            char base = (isupper(ch)) ? 'A' : 'a';
            result += static_cast<char>((ch - base + shift) % 26 + base);
        }
        else
        {
            result += ch;
        }
    }

    return result;
}

string decrypt(const string &message, int shift)
{

    return encrypt(message, -shift);
}

int main()
{

    string message;
    cout << "Enter a message to encrypt: ";
    getline(cin, message);

    int shift;
    cout << "Enter the shift value: ";
    cin >> shift;

    string encryptedMessage = encrypt(message, shift);
    cout << "Encrypted message: " << encryptedMessage << endl;

    string decryptedMessage = decrypt(encryptedMessage, shift);
    cout << "Decrypted message: " << decryptedMessage << endl;

    return 0;
}
