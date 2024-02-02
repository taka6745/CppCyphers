#include "CaesarCipher.h"

std::string CaesarCipher::encrypt(const std::string& text, const std::string& key) {
    std::string result = "";
    int shift = std::stoi(key) % 26; // Ensure the shift is within the alphabet range

    for (char c : text) {
        if (isupper(c)) {
            // Shift uppercase letters
            char shifted = 'A' + (c - 'A' + shift) % 26;
            result += shifted;
        } else if (islower(c)) {
            // Shift lowercase letters
            char shifted = 'a' + (c - 'a' + shift) % 26;
            result += shifted;
        } else {
            // Non-alphabetic characters are not modified
            result += c;
        }
    }

    return result;
}

std::string CaesarCipher::decrypt(const std::string& cipherText, const std::string& key) {
    std::string result = "";
    int shift = std::stoi(key) % 26; // Ensure the shift is within the alphabet range
    int reverseShift = 26 - shift; // Calculate the reverse shift for decryption

    for (char c : cipherText) {
        if (isupper(c)) {
            // Reverse shift for uppercase letters
            char shifted = 'A' + (c - 'A' + reverseShift) % 26;
            result += shifted;
        } else if (islower(c)) {
            // Reverse shift for lowercase letters
            char shifted = 'a' + (c - 'a' + reverseShift) % 26;
            result += shifted;
        } else {
            // Non-alphabetic characters are not modified
            result += c;
        }
    }

    return result;
}
