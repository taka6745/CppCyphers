#include "VigenereCipher.h"
#include <cctype> // for std::toupper

// Helper function to map A-Z to 0-25
int charToIndex(char c) {
    return std::toupper(c) - 'A';
}

// Encrypts text using a key
std::string VigenereCipher::encrypt(const std::string& text, const std::string& key) {
    std::string result;
    int keyIndex = 0;
    for (char c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int shift = charToIndex(key[keyIndex % key.length()]);
            result += static_cast<char>((charToIndex(c) + shift) % 26 + base);
            keyIndex++;
        } else {
            // Non-alphabetic characters are copied as-is
            result += c;
        }
    }
    return result;
}

// Decrypts text using a key
std::string VigenereCipher::decrypt(const std::string& cipherText, const std::string& key) {
    std::string result;
    int keyIndex = 0;
    for (char c : cipherText) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int shift = charToIndex(key[keyIndex % key.length()]);
            result += static_cast<char>((charToIndex(c) - shift + 26) % 26 + base);
            keyIndex++;
        } else {
            // Non-alphabetic characters are copied as-is
            result += c;
        }
    }
    return result;
}
