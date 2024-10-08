#include <iostream>
#include "ui/cli.h"    // Including the CLI interface
#include "networking/server.h"
#include "networking/client.h"

// This is the main entry point of the application
int main() {
    // Display the CLI menu
    int choice = display_main_menu();
    
    if (choice == 1) {
        // Start the server
        start_server();
    } else if (choice == 2) {
        // Start the client
        start_client();
    } else {
        std::cout << "Exiting..." << std::endl;
    }

    return 0;
}
