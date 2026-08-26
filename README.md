# RC4 File Encryptor

## Overview

This project implements an RC4 stream cipher file encryptor and decryptor in C++.

The program reads the contents of `file.txt` in binary mode, encrypts the bytes using RC4 with a specified key, and writes the encrypted data back to the file.

The decryptor uses the same RC4 key to restore the original contents.

## Files

- `encryptor.cpp` - Encrypts `file.txt` using RC4.
- `decryptor.cpp` - Decrypts `file.txt` using the same RC4 key.
- `file.txt` - Test file used by the programs.

## RC4 Process

RC4 consists of two main stages:

1. Key Scheduling Algorithm (KSA)
2. Pseudo-Random Generation Algorithm (PRGA)

The generated RC4 keystream is XORed with the file data.

Encryption:

```text
Plaintext XOR Keystream = Ciphertext
