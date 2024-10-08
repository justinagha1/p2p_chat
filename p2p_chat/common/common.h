#ifndef COMMON_H
#define COMMON_H

#include <boost/asio.hpp>

// Function declarations for sending and receiving
void handle_receive(boost::asio::ip::tcp::socket& socket, unsigned char* key);
void handle_send(boost::asio::ip::tcp::socket& socket, unsigned char* key);

#endif
