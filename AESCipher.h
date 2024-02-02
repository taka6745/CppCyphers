#ifndef AESCIPHER_H
#define AESCIPHER_H

#include "CipherManager.h"
#include <string>

class AESCipher : public CipherManager {
public:
    AESCipher(); 
    ~AESCipher(); 

    std::string encrypt(const std::string& text, const std::string& key) override;
    std::string decrypt(const std::string& cipherText, const std::string& key) override;

private:
    std::string performAESOperation(const std::string& input, const std::string& key, bool encrypting);
};

#endif // AESCIPHER_H
