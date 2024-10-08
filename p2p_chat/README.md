
# P2P Serverless Encrypted Chat Application

This is a serverless peer-to-peer (P2P) chat application built using C++ that utilises the TCP/IP stack to establish a two-way communication channel between two clients, with encryption of messages using AES.

**This application is serverless in the sense that it doesn't use a central server for message routing.** Instead, it allows two clients to connect directly to each other and exchange messages. This application is capable of sending and receiving encrypted messages in real-time.

## Features

- **Two-Way Communication**: Both the server and the client can send and receive messages simultaneously using multithreading.
- **End-to-End Encryption**: All messages are encrypted using AES encryption.
- **TCP/IP Networking**: Uses the Boost.Asio library to handle the networking aspects.
- **Cross-Platform**: Works on macOS (have not tested other platforms such as Linux or Windows).

## Prerequisites

To build and run this program, you need the following tools and libraries installed:

### Tools

- **C++ Compiler**: (e.g., `g++` or `clang++`)
- **CMake**: To manage the build process
- **Boost Libraries**: For networking (`Boost.Asio`)
- **OpenSSL**: For encryption (AES)

### Installation

On **macOS** (using Homebrew):

```bash
brew install boost openssl cmake
```

## Project Structure

The project will be structured as follows:

```
/serverless-chat
    ├── CMakeLists.txt
    ├── main.cpp
    ├── networking/
    │   ├── server.cpp
    │   ├── server.h
    │   ├── client.cpp
    │   ├── client.h
    ├── encryption/
    │   ├── encrypt.cpp
    │   ├── encrypt.h
    │   ├── decrypt.cpp
    │   ├── decrypt.h
    ├── ui/
    │   ├── cli.cpp
    │   ├── cli.h
    ├── common/
    │   ├── common.cpp
    │   ├── common.h
```

- **`networking/`**: Contains server and client logic for handling TCP connections.
- **`encryption/`**: Contains functions for encrypting and decrypting messages using AES (via OpenSSL).
- **`ui/`**: Contains code for a simple CLI interface.
- **`common/`**: Contains shared functions (e.g., sending and receiving messages) used by both the server and client.

## How to Build and Run

### Step 1: Clone the Repository from
https://github.com/justinagha1/p2p-chat.git

### Step 2: Build the Application

1. **Create a `build` directory**:

   ```bash
   mkdir build
   cd build
   ```

2. **Generate the build files using CMake**:

   ```bash
   cmake ..
   ```

   This will configure your project and generate the necessary Makefiles.

3. **Compile the project**:

   ```bash
   make
   ```

   After compilation, the executable `serverless-chat` will be created in the `build/` directory.

### Step 3: Run the Application

#### Running the Server

1. Open a terminal and navigate to the `build` directory:

   ```bash
   cd build
   ```

2. Start the server:

   ```bash
   ./serverless-chat
   ```

3. Choose the server option (enter `1`):

   ```bash
   === Serverless Chat Application ===
   1. Start Server
   2. Start Client
   3. Exit
   Select an option: 1
   ```

4. The server will start and wait for the client to connect.

#### Running the Client

1. Open another terminal and navigate to the `build` directory:

   ```bash
   cd build
   ```

2. Start the client:

   ```bash
   ./serverless-chat
   ```

3. Choose the client option (enter `2`):

   ```bash
   === Serverless Chat Application ===
   1. Start Server
   2. Start Client
   3. Exit
   Select an option: 2
   ```

4. The client will attempt to connect to the server.

5. Once connected, both the client and the server can send and receive encrypted messages.

## Example Usage

Once both the server and the client are running, they can communicate with each other. For example:

- On the server terminal, type:
  ```bash
  Server: Hello, Client!
  ```

- On the client terminal, you will see:
  ```bash
  Server: Hello, Client!
  ```

- On the client terminal, type:
  ```bash
  Client: Hello, Server!
  ```

- On the server terminal, you will see:
  ```bash
  Client: Hello, Server!
  ```


## Known Issues

- **Encryption key**: The encryption key is hardcoded for simplicity. For production, implement a more secure encyryption mechanism like SHA256.

- **characters**: Unable to enter more than 16 characters between server and client.
