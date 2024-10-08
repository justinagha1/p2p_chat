#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <vector>
#include <string>

std::vector<unsigned char> encrypt_message(const std::string& message, unsigned char* key);

#endif
