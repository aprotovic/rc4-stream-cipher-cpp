# RC4 Symmetric Stream Cipher Implementation (C++)

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![Domain](https://img.shields.io/badge/Domain-Applied%20Cryptography-green.svg)
![License](https://img.shields.io/badge/License-MIT-lightgrey.svg)

An educational implementation of the **Rivest Cipher 4 (RC4)** symmetric stream cipher written in standard C++. This project demonstrates foundational cryptographic algorithms: state permutation, pseudo-random keystream generation, and symmetric XOR stream transformation for file data.

---

## 🔬 Algorithmic Overview

RC4 is a variable key-size stream cipher with byte-oriented operations. The algorithm is based on the use of a random permutation. It consists of two primary sub-routines:

### 1. Key-Scheduling Algorithm (KSA)
The state array `S[0..255]` is initialized with values from `0` to `255`. The secret key is then used to pseudo-randomly permute the array over 256 iterations:

$$\begin{aligned}
S[i] &= i \quad \text{for } i \in [0, 255] \\
j &= (j + S[i] + \text{Key}[i \pmod L]) \pmod{256} \\
\text{swap}(&S[i], S[j])
\end{aligned}$$

### 2. Pseudo-Random Generation Algorithm (PRGA)
Once the state array is permuted, keystream bytes $K$ are generated dynamically and applied via bitwise XOR ($\oplus$) to the plaintext bytes:

$$\begin{aligned}
i &= (i + 1) \pmod{256} \\
j &= (j + S[i]) \pmod{256} \\
\text{swap}(&S[i], S[j]) \\
K &= S[(S[i] + S[j]) \pmod{256}] \\
\text{Ciphertext}[k] &= \text{Plaintext}[k] \oplus K
\end{aligned}$$

Because XOR is its own inverse ($A \oplus K \oplus K = A$), the exact same keystream regenerates the original plaintext during decryption.

---

## 📂 Project Structure

```
├── encrypt.cpp   # Key-Scheduling & PRGA file encryption logic
├── decrypt.cpp   # Symmetric decryption logic
├── file.txt      # Sample text payload for algorithmic verification
└── README.md     # Project documentation
```

---

## 🚀 Compilation & Usage

### Prerequisites
* A standard C++ compiler (`g++`, `clang++`, or MSVC) supporting C++11 or newer.

### 1. Compilation
Compile both programs using `g++`:

```bash
g++ -O2 encrypt.cpp -o encrypt
g++ -O2 decrypt.cpp -o decrypt
```

### 2. Execution

1. Prepare your target file `file.txt` with sample text.
2. Run the encryption executable:
   ```bash
   ./encrypt
   ```
   *The file bytes in `file.txt` are now encrypted via RC4 keystream XOR.*

3. Run the decryption executable to reverse the transformation:
   ```bash
   ./decrypt
   ```
   *The file is restored cleanly to its original plaintext format.*

---

## ⚖️ Academic & Ethical Disclaimer

This repository was created strictly for **academic and educational purposes** to study theoretical stream ciphers and symmetric cryptographic primitives in Computer Science. It does not contain any payload delivery mechanisms, evasion techniques, or malicious code. Modern cryptanalysis has demonstrated statistical biases in RC4; therefore, this implementation is intended for algorithmic demonstration and learning rather than modern production security.

---

## 📄 License
This project is open-source under the [MIT License](LICENSE).
