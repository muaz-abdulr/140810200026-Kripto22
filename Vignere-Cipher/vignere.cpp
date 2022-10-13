#include <bits/stdc++.h>
using namespace std;

int convertKey(char n)
{
    // konversi tiap karakter key ke angka
    if (isupper(n))
    {
        return n - 65;
    }
    else if (islower(n))
    {
        return n - 97;
    }
    return -1;
}

string enkripsi(string plain_text, string key)
{
    string cipher_text = "";
    // panjang key dicatat sebagai modulo
    int key_len = key.length();
    int whitespace = 0;
    for (int i = 0; i < plain_text.size(); i++)
    {
        // agar key dapat diloop, setiap i akan dimodulokan dengan pangjang key
        // variabel whitespace menyatakan offset i ketika bertemu whitespace
        int key_char = convertKey(key[(i - whitespace) % key_len]);
        if (isupper(plain_text[i]))
        {
            cipher_text += char(int(plain_text[i] + key_char - 65) % 26 + 65);
        }
        else if (islower(plain_text[i]))
        {
            cipher_text += char(int(plain_text[i] + key_char - 97) % 26 + 97);
        }
        else
        {
            whitespace += 1;
            cipher_text += plain_text[i];
        }
    }
    return cipher_text;
}

string dekripsi(string cipher_text, string key)
{
    string plain_text = "";
    // panjang key dicatat sebagai modulo
    int key_len = key.length();
    int whitespace = 0;
    for (int i = 0; i < cipher_text.size(); i++)
    {
        // agar key dapat diloop, setiap i akan dimodulokan dengan pangjang key
        // variabel whitespace menyatakan offset i ketika bertemu whitespace
        int key_char = convertKey(key[(i - whitespace) % key_len]);
        if (isupper(cipher_text[i]))
        {
            plain_text += char((int(cipher_text[i] - key_char - 65) % 26 + 26) % 26 + 65);
        }
        else if (islower(cipher_text[i]))
        {
            plain_text += char((int(cipher_text[i] - key_char - 97) % 26 + 26) % 26 + 97);
        }
        else
        {
            whitespace += 1;
            plain_text += cipher_text[i];
        }
    }
    return plain_text;
}

int main()
{
    string plain_text, key;
    cout << "PROGRAM Vignere CIPHER" << endl;
    cout << "Masukan Plaintext : ";
    getline(cin, plain_text);
    cout << "Masukan Kunci : ";
    ws(cin);
    cin >> key;
    string cipher_text = enkripsi(plain_text, key);

    cout << "\nEnkripsi : \n";
    cout << "Ciphertext : " << cipher_text << endl;

    cout << "\nDekripsi:\n";
    cout << "Plaintext : " << dekripsi(cipher_text, key) << endl;
}