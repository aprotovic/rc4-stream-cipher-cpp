#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const string KEY = "TeamBravoRC4Key";

void rc4(vector<unsigned char>& data) {
    unsigned char S[256];

    for (int i = 0; i < 256; i++) {
        S[i] = i;
    }

    int j = 0;

    // KSA
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + KEY[i % KEY.length()]) & 0xFF;
        swap(S[i], S[j]);
    }

    // PRGA + XOR
    int i = 0;
    j = 0;

    for (size_t k = 0; k < data.size(); k++) {
        i = (i + 1) & 0xFF;
        j = (j + S[i]) & 0xFF;

        swap(S[i], S[j]);

        unsigned char keystream =
            S[(S[i] + S[j]) & 0xFF];

        data[k] ^= keystream;
    }
}

int main() {
    const string filename = "file.txt";

    ifstream input(filename, ios::binary);

    if (!input) {
        cerr << "Could not open file.txt\n";
        return 1;
    }

    vector<unsigned char> data(
        (istreambuf_iterator<char>(input)),
        istreambuf_iterator<char>()
    );

    input.close();

    rc4(data);

    ofstream output(filename, ios::binary);

    if (!output) {
        cerr << "Could not write file.txt\n";
        return 1;
    }

    output.write(
        reinterpret_cast<const char*>(data.data()),
        data.size()
    );

    output.close();

    cout << "File encrypted successfully.\n";

    return 0;
}