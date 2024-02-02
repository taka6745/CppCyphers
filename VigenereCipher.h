#ifndef VIGENERECIPHER_H
#define VIGENERECIPHER_H

#include "CipherManager.h"

class VigenereCipher : public CipherManager {
public:
    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& cipherText, const std::string& key) override;
};

#endif // VIGENERECIPHER_H
