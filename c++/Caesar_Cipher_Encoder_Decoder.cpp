#include <iostream>
#include <string>

using namespace std;

void decode() {
    string in_str;
    cout << "Enter the string to decode: ";
    cin >> in_str; // Note: using cin will stop at whitespace. Consider using getline if input may have spaces.

    bool isKey = false;
    char check;
    cout << "Do you have a key? (Y/n): ";
    cin >> check;

    if (check == 'y' || check == 'Y') {
        isKey = true;
    }

    if (isKey) {
        long long key;
        cout << "Enter key for decryption: ";
        cin >> key;

        if (key < 0) {
            cout << "Key has to be positive!" << endl;
            return;
        }

        // Decrypting with the provided key
        for (long long i = 0; i < (long long)in_str.length(); i++) {
            char &ch = in_str[i]; // Reference for easier modification
            if (ch >= 'A' && ch <= 'Z') {
                ch = 'A' + (ch - 'A' - key + 26) % 26; // Ensure positive modulo
            } else if (ch >= 'a' && ch <= 'z') {
                ch = 'a' + (ch - 'a' - key + 26) % 26; // Ensure positive modulo
            }
        }
        cout << "Decoded string is --> " << in_str << endl;
    } else {
        cout << "Bruteforcing all 26 combinations..." << endl;
        for (long long key = 0; key < 26; key++) {
            string str = in_str; // Copy input for each key
            for (long long i = 0; i < (long long)str.length(); i++) {
                char &ch = str[i]; // Reference for easier modification
                if (ch >= 'A' && ch <= 'Z') {
                    ch = 'A' + (ch - 'A' - key + 26) % 26; // Ensure positive modulo
                } else if (ch >= 'a' && ch <= 'z') {
                    ch = 'a' + (ch - 'a' - key + 26) % 26; // Ensure positive modulo
                }
            }
            cout << "Key " << key << " --> " << str << endl;
        }
    }
}

void encode() {
    string str;
    cout << "Enter the string to encode: ";
    cin >> str; // Note: using cin will stop at whitespace. Consider using getline if input may have spaces.

    long long key;
    cout << "Enter key for encryption: ";
    cin >> key;

    if (key < 0) {
        cout << "Key has to be positive!" << endl;
        return;
    }

    // Encrypting with the provided key
    for (long long i = 0; i < (long long)str.length(); i++) {
        char &ch = str[i]; // Reference for easier modification
        if (ch >= 'A' && ch <= 'Z') {
            ch = 'A' + (ch - 'A' + key) % 26; // Ensure wrapping around
        } else if (ch >= 'a' && ch <= 'z') {
            ch = 'a' + (ch - 'a' + key) % 26; // Ensure wrapping around
        }
    }
    cout << "Encoded string is --> " << str << endl;
}

int main() {
    cout << "Caesar Cipher Encoder and Decoder" << endl;
    long long option;
    cout << "Modes:\n1.Decode\n2.Encode\n3.Exit\nChosen Mode: ";
    cin >> option;

    if (option == 1) {
        decode();
    } else if (option == 2) {
        encode();
    } else if (option == 3) {
        cout << "Thanks for using! Exiting now." << endl;
    } else {
        cout << "Invalid option! Please select 1, 2, or 3." << endl;
    }
    return 0;
}
