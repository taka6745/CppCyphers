#include "AESCipher.h"
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <cstring>

std::string AESCipher::encrypt(const std::string& text, const std::string& key) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    /* Assuming key is 256 bits and properly formatted for AES-256 */
    unsigned char *iv = (unsigned char *)"0123456789012345"; // Initialization vector

    /* Buffer for the ciphertext, ensure it is large enough */
    unsigned char ciphertext[1024];

    /* Create and initialize the context */
    if(!(ctx = EVP_CIPHER_CTX_new())) return "";

    /* Initialize encryption operation with AES-256-CBC */
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, reinterpret_cast<const unsigned char*>(key.c_str()), iv))
        return "";

    /* Provide the message to be encrypted, and obtain the encrypted output */
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, reinterpret_cast<const unsigned char*>(text.c_str()), text.length()))
        return "";
    ciphertext_len = len;

    /* Finalize encryption */
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) return "";
    ciphertext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return std::string(reinterpret_cast<char*>(ciphertext), ciphertext_len);
}

std::string AESCipher::decrypt(const std::string& cipherText, const std::string& key) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;
    unsigned char *iv = (unsigned char *)"0123456789012345"; // Same IV as for encryption

    /* Buffer for the decrypted text */
    unsigned char plaintext[1024];

    /* Create and initialize the context */
    if(!(ctx = EVP_CIPHER_CTX_new())) return "";

    /* Initialize decryption operation with AES-256-CBC */
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, reinterpret_cast<const unsigned char*>(key.c_str()), iv))
        return "";

    /* Provide the message to be decrypted, and obtain the plaintext output */
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, reinterpret_cast<const unsigned char*>(cipherText.c_str()), cipherText.length()))
        return "";
    plaintext_len = len;

    /* Finalize decryption */
    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) return "";
    plaintext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return std::string(reinterpret_cast<char*>(plaintext), plaintext_len);
}
