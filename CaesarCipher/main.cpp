#include "CaesarCipher.h"

int main() {
    string input_filename;
    cout << "Enter input file name: ";
    cin >> input_filename;

    int shift;
    cout << "Enter shift value: ";
    cin >> shift;

    CaesarCipher cipher(shift);

    cipher.encrypt(input_filename);
    cipher.decrypt("e_" + input_filename);

    cout << "Encryption and decryption complete. New files created" << endl;

    return 0;
}
