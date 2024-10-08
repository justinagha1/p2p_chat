#include "common.h"
#include "../encryption/encrypt.h"
#include "../encryption/decrypt.h"
#include <iostream>
#include <vector>
#include <string>

// Function to handle receiving data
void handle_receive(boost::asio::ip::tcp::socket& socket, unsigned char* key) {
    while (true) {
        std::vector<char> buf(1024);  // Buffer to store incoming data
        boost::system::error_code error; // Error code to check for connection closure
        size_t len = socket.read_some(boost::asio::buffer(buf), error);

        // If the connection is closed by the peer, break the loop
        if (error == boost::asio::error::eof) {
            std::cout << "Connection closed by peer." << std::endl;
            break;
        } else if (error) {
            throw boost::system::system_error(error);
        }

        // Decrypt the received message
        std::string decrypted_message = decrypt_message(reinterpret_cast<const unsigned char*>(buf.data()), key);
        std::cout << "Received: " << decrypted_message << std::endl;
    }
}

// Function to handle sending data
void handle_send(boost::asio::ip::tcp::socket& socket, unsigned char* key) {
    while (true) {
        std::string message;
        std::cout << "Enter message: ";
        std::getline(std::cin, message);  // Get user input

        // Encrypt the message
        std::vector<unsigned char> encrypted_message = encrypt_message(message, key);

        // Send the encrypted message
        boost::asio::write(socket, boost::asio::buffer(encrypted_message));
    }
}
