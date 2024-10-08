#include <iostream> // For std::cout
#include <boost/asio.hpp> // Include the asio library
#include <thread> // For std::thread to handle multiple threads
#include "../common/common.h"  // Use the common functions from here

using boost::asio::ip::tcp;


void start_server() {
    boost::asio::io_service io_service; // IO service to handle asynchronous operations
    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 1234));  // Initializes a TCP acceptor that listens for connections on IPv4 at port 1234
    tcp::socket socket(io_service); // Socket to handle the client connection

    std::cout << "Waiting for client connection..." << std::endl;
    acceptor.accept(socket);  // Accept a new connection assigns it to socket

    std::cout << "Client connected!" << std::endl;

    unsigned char key[16] = {0};  // encryption key I have hard-coded (shared by both server and client to encrypt messages)

    // Start two threads: one for receiving and one for sending
    std::thread receiver(handle_receive, std::ref(socket), key);
    std::thread sender(handle_send, std::ref(socket), key);

    // Join the threads to ensure the main thread waits for them to finish
    receiver.join();
    sender.join();
}
