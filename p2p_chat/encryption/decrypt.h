#ifndef DECRYPT_H
#define DECRYPT_H

#include <vector>
#include <string>

std::string decrypt_message(const unsigned char* ciphertext, unsigned char* key);

#endif
