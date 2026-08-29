#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string KEY = "MyK3y4th!s";

void rc4(string& text) {
    unsigned char S[256];

    for (int i = 0; i < 256; i++) {
        S[i] = i;
    }

    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + KEY[i % KEY.length()]) & 0xFF;
        swap(S[i], S[j]);
    }

    int i = 0;
    j = 0;

    for (size_t k = 0; k < text.size(); k++) {
        i = (i + 1) & 0xFF;
        j = (j + S[i]) & 0xFF;
        swap(S[i], S[j]);

        unsigned char keyByte = S[(S[i] + S[j]) & 0xFF];
        text[k] = text[k] ^ keyByte;
    }
}

int main() {
    string filename = "file.txt";
    ifstream in(filename, ios::binary);

    string text;
    char ch;
    while (in.get(ch)) {
        text += ch;
    }
    in.close();

    rc4(text);

    ofstream out(filename, ios::binary);
    for (size_t i = 0; i < text.size(); i++) {
        out.put(text[i]);
    }
    out.close();

    cout << "File encrypted successfully.\n";
    return 0;
}