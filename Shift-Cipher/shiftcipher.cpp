/*
Nama	: Muhammad Danendra Syah Hidayatullah 
NPM	    : 140810220064
Kelas	: B
Program : Membuat program Shift Cipher dengan bahasa pemrograman bebas
*/

#include <iostream>
#include <string>

using namespace std;

string encrypt(string plaintext, int shift) {
    string ciphertext = "";
    shift = shift % 26;

    for (int i = 0; i < plaintext.length(); i++) {
        char ch = plaintext[i];

        if (isalpha(ch)) {
            if (isupper(ch)) {
                ciphertext += char((int(ch - 'A') + shift) % 26 + 'A');
            } else {
                ciphertext += char((int(ch - 'a') + shift) % 26 + 'a');
            }
        } else {
            ciphertext += ch;
        }
    }

    return ciphertext;
}

string decrypt(string ciphertext, int shift) {
    string plaintext = "";
    shift = shift % 26;

    for (int i = 0; i < ciphertext.length(); i++) {
        char ch = ciphertext[i];

        if (isalpha(ch)) {
            if (isupper(ch)) {
                plaintext += char((int(ch - 'A') - shift + 26) % 26 + 'A');
            } else {
                plaintext += char((int(ch - 'a') - shift + 26) % 26 + 'a');
            }
        } else {
            plaintext += ch;
        }
    }

    return plaintext;
}

int main() {
    string text;
    int shift;

    cout << "Masukkan teks: ";
    getline(cin, text);

    cout << "Masukkan besar pergeseran (shift): ";
    cin >> shift;

    string encryptedText = encrypt(text, shift);
    cout << "Teks terenkripsi: " << encryptedText << endl;

    string decryptedText = decrypt(encryptedText, shift);
    cout << "Teks terdekripsi: " << decryptedText << endl;

    return 0;
}
