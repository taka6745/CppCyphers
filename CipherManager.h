#ifndef CIPHERMANAGER_H
#define CIPHERMANAGER_H

#include <string>

class CipherManager {
public:
    virtual std::string encrypt(const std::string& text, const std::string& key) = 0;
    virtual std::string decrypt(const std::string& cipherText, const std::string& key) = 0;
};

#endif // CIPHERMANAGER_H
