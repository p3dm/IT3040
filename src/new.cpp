#include <iostream>
#include <string>
#include <cctype> // for toupper()

int main() {
    std::string line;
    std::string text;

    // Read input line by line until EOF
    while (std::getline(std::cin, line)) {
        text.append(line).append("\n");
    }

    // Convert the entire text to uppercase
    for (char& c : text) {
        c = std::toupper(static_cast<unsigned char>(c));
    }

    // Print the uppercase text
    std::cout << text;

    return 0;
}
