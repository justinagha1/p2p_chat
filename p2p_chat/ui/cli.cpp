#include <iostream>

int display_main_menu() {
    std::cout << "=== Serverless Chat Application ===\n";
    std::cout << "1. Start Server\n";
    std::cout << "2. Start Client\n";
    std::cout << "3. Exit\n";
    std::cout << "Select an option: ";
    
    int choice;
    std::cin >> choice;
    std::cin.ignore();  // To handle the newline character
    
    return choice;
}
