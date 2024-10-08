cmake_minimum_required(VERSION 3.10)
project(ServerlessChat)

set(CMAKE_CXX_STANDARD 11)

# Add the specific include paths for OpenSSL and Boost
include_directories(
    ${CMAKE_SOURCE_DIR}
    "/opt/homebrew/opt/openssl@3/include"
    "/opt/homebrew/opt/boost/include"
)

# Add all the source files
add_executable(serverless-chat
    main.cpp
    networking/server.cpp
    networking/client.cpp
    encryption/encrypt.cpp
    encryption/decrypt.cpp
    ui/cli.cpp
    common/common.cpp
)

# Find OpenSSL
find_package(OpenSSL REQUIRED)

# Find Boost
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS system)

# Link the required libraries
target_link_libraries(serverless-chat
    OpenSSL::SSL
    OpenSSL::Crypto
    Boost::system
    pthread
)

# Add the library paths for OpenSSL and Boost
link_directories(
    "/opt/homebrew/opt/openssl@3/lib"
    "/opt/homebrew/opt/boost/lib"
)
