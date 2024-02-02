#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include "CipherManager.h"

class CaesarCipher : public CipherManager {
public:
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& cipherText, const std::string& key) override;
};

#endif // CAESARCIPHER_H
