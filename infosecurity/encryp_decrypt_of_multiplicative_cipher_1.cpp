#include <iostream>
#include <string>
#include<cmath>
using namespace std;

int gcd(int x, int y){
    while(y!=0){
        int temp =y;
        y = x%y;
        x = temp;
        }
    return x;
}
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}
string encrypt(string plaintext, int key) {
    string ciphertext = "";
    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';

            char encryptedChar = (char)((((ch - base) * key) % 26) + base);
            ciphertext += encryptedChar;
        } else {
            ciphertext += ch;
        }
    }
    return ciphertext;
}
string decrypt(string ciphertext, int key) {
    int inverseKey = modInverse(key, 26);
    if (inverseKey == -1) {
        cout << "Error: No modular inverse found for the key." << endl;
        return "";
        }
       string plaintext = "";
    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';

            char decryptedChar = (char)((((ch - base) * inverseKey) % 26 + 26) % 26 + base);
            plaintext += decryptedChar;
        } else {
            plaintext += ch;
        }
    }
    return plaintext;
}
int main() {
    string message;
    int key;
    cout << "Enter the message to encrypt: ";
    getline(cin, message);
    cout << "Enter the key (must be coprime with 26): ";
    cin >> key;
    if (key <= 0 || key >= 26 || gcd(key, 26) != 1) {
        cout << "Invalid key. It must be coprime with 26." << endl;
        return 1;
    }
    string encryptedMessage = encrypt(message, key);
    cout << "Encrypted Message: " << encryptedMessage << endl;
    string decryptedMessage = decrypt(encryptedMessage, key);
    cout << "Decrypted Message: " << decryptedMessage << endl;
    return 0;
}
