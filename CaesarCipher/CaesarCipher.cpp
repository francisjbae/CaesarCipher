#include "CaesarCipher.h"

CaesarCipher::CaesarCipher(int _shift) 
{
    shift = _shift;
}
void CaesarCipher::setShift(int _shift) 
{
    shift = _shift;
}
int CaesarCipher::getShift() 
{
    return shift;
}
void CaesarCipher::encrypt(string filename) 
{
    ifstream input_file(filename);
    if (!input_file) 
    {
        cerr << "Error: File could not be opened." << endl;
        exit(1);
    }
    string encrypted_filename = "e_" + filename;
    ofstream output_file(encrypted_filename);
    if (!output_file) 
    {
        cerr << "Error: File could not be created." << endl;
        exit(1);
    }
    char c;
    while (input_file.get(c)) 
    {
        if (isalpha(c)) 
        {
            if (islower(c)) 
            {
                c = ((c - 'a' + shift) % 26) + 'a';
            } else 
            {
                c = ((c - 'A' + shift) % 26) + 'A';
            }
        }
        output_file << c;
    }
    input_file.close();
    output_file.close();
}
void CaesarCipher::decrypt(string filename) 
{
    ifstream input_file(filename);
    if (!input_file) 
    {
        cerr << "Error: File could not be opened." << endl;
        exit(1);
    }
    string decrypted_filename = "d_" + filename.substr(2, filename.size() - 2);
    ofstream output_file(decrypted_filename);
    if (!output_file) 
    {
        cerr << "Error: File could not be created." << endl;
        exit(1);
    }
    char c;
    while (input_file.get(c)) 
    {
        if (isalpha(c)) 
        {
            if (islower(c)) 
            {
                c = ((c - 'a' - shift + 26) % 26) + 'a';
            } else 
            {
                c = ((c - 'A' - shift + 26) % 26) + 'A';
            }
        }
        output_file << c;
    }
    input_file.close();
    output_file.close();
}