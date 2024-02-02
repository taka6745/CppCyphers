# Cryptography Application in C++

## Overview
This C++ application is an educational tool for exploring basic cryptographic techniques. It implements Caesar cipher, Vigenère cipher, and AES encryption and decryption. The application provides a simple console interface to interact with these cryptographic methods.

## Features
- **Caesar Cipher**: A substitution cipher where each letter in the plaintext is shifted a certain number of places down the alphabet.
- **Vigenère Cipher**: A method of encrypting alphabetic text by using a simple form of polyalphabetic substitution.
- **AES Encryption/Decryption**: Advanced Encryption Standard implemented using a cryptographic library for secure and efficient operations.

## Requirements
- C++ Compiler (GCC recommended)
- OpenSSL library (for AES operations)

## Compilation and Running
Ensure that OpenSSL is installed and properly set up on your system. Compile the application using a C++ compiler. For example, using g++:

```bash
g++ -o crypto_app main.cpp CaesarCipher.cpp VigenereCipher.cpp AESCipher.cpp -lssl -lcrypto
