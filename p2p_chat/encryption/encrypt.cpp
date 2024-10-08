#include <openssl/aes.h>
#include <vector>
#include <string>

std::vector<unsigned char> encrypt_message(const std::string& message, unsigned char* key) {
    AES_KEY encrypt_key;
    AES_set_encrypt_key(key, 128, &encrypt_key);
    
    std::vector<unsigned char> ciphertext(128);  // AES block size
    
    AES_encrypt(reinterpret_cast<const unsigned char*>(message.c_str()), ciphertext.data(), &encrypt_key); // Encrypt the message   
    
    return ciphertext;  // Return encrypted data
}
