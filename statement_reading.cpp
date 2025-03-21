#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::string filePath;
    std::cout << "Enter the path to the payment statement file: ";
    std::cin >> filePath;

    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    double total = 0.0;
    double maxAmount = 0.0;
    std::string maxRecipient;
    std::string lineBuffer;

    // Stream-based processing
    while (std::getline(inputFile, lineBuffer)) {
        std::istringstream lineStream(lineBuffer);
        std::string firstName, lastName, date;
        double amount;

        if (lineStream >> firstName >> lastName >> amount >> date) {
            total += amount;
            if (amount > maxAmount) {
                maxAmount = amount;
                maxRecipient = firstName + " " + lastName;
            }
        } else {
            std::cerr << "Invalid format in line: " << lineBuffer << '\n';
        }
    }

    std::cout << "\nTotal payments: $" << total
              << "\nTop recipient: " << maxRecipient 
              << " ($" << maxAmount << ")\n";

    inputFile.close();
    return 0;
}
