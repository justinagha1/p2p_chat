#include <openssl/aes.h>
#include <vector>
#include <string>

std::string decrypt_message(const unsigned char* ciphertext, unsigned char* key) {
    AES_KEY decrypt_key;
    AES_set_decrypt_key(key, 128, &decrypt_key);
    
    std::vector<unsigned char> plaintext(128);  // Buffer for decrypted text
    
    AES_decrypt(ciphertext, plaintext.data(), &decrypt_key); // Decrypt the ciphertext
    
    return std::string(plaintext.begin(), plaintext.end());  // Return decrypted text
}
