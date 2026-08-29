# RC4 File Encryptor

This is a small C++ project that uses RC4 to change a file and then bring it back to normal.

The encryptor reads the file, mixes it with a key, and saves the changed version.
The decryptor uses the same key to reverse it and get the original file back.

## Files

- encrypt.cpp - changes the file
- decrypt.cpp - restores the file
- file.txt - the file used for testing

## Simple idea

The program makes a list of numbers from 0 to 255, shuffles them with the key, and then uses those numbers to change the file bytes.

It uses XOR, so the same process can undo the change later.

## Run it

```bash
g++ encrypt.cpp -o encrypt
g++ decrypt.cpp -o decrypt
./encrypt
./decrypt
```

This is a basic RC4 example to learn how stream ciphers work in a simple way.

