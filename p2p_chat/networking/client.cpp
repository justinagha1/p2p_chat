#include <iostream>
#include <boost/asio.hpp>
#include <thread>
#include "../common/common.h"  // Use the common functions from here

using boost::asio::ip::tcp;

void start_client() {


    boost::asio::io_service io_service; // IO service to handle asynchronous operations
    tcp::resolver resolver(io_service); // Resolver to resolve the server address
    tcp::resolver::query query("1234"); // Query to resolve the server address
    tcp::resolver::iterator endpoint_iterator = resolver.resolve(query); // Iterator to resolve the server address

    tcp::socket socket(io_service); // Socket to handle the connection
    boost::asio::connect(socket, endpoint_iterator);  // Connect to server

    std::cout << "Connected to server!" << std::endl;

    unsigned char key[16] = {0};  // Example encryption key (shared by both server and client)

    // Start two threads: one for receiving and one for sending
    std::thread receiver(handle_receive, std::ref(socket), key);
    std::thread sender(handle_send, std::ref(socket), key);

    // Join the threads to ensure the main thread waits for them to finish
    receiver.join();
    sender.join();
}
