#include "CaesarCipher.h"
#include "VigenereCipher.h"
#include "AESCipher.h"
#include <iostream>
#include <memory>

int main() {
    std::cout << "Choose cipher (1: Caesar, 2: Vigenere, 3: AES): ";
    int choice;
    std::cin >> choice;

    std::cin.ignore(); // Clear out the newline character from the input buffer

    std::string text, key;
    std::cout << "Enter text: ";
    std::getline(std::cin, text);

    std::cout << "Enter key: ";
    std::getline(std::cin, key);

    std::unique_ptr<CipherManager> cipher;

    switch(choice) {
        case 1:
            cipher = std::make_unique<CaesarCipher>();
            break;
        case 2:
            cipher = std::make_unique<VigenereCipher>();
            break;
        case 3:
            cipher = std::make_unique<AESCipher>();
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
            return 1;
    }

    std::string encrypted = cipher->encrypt(text, key);
    std::string decrypted = cipher->decrypt(encrypted, key);

    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}
