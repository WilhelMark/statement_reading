#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// Structure to store payment information
struct Payment {
    std::string firstName;
    std::string lastName;
    double amount;
    std::string date;
};

int main() {
    std::string filePath;
    std::cout << "Enter the path to the payment statement file: ";
    std::cin >> filePath;

    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::vector<Payment> payments;
    Payment currentPayment;
    
    // Read and parse each line from the file
    while (inputFile >> currentPayment.firstName 
                     >> currentPayment.lastName 
                     >> currentPayment.amount 
                     >> currentPayment.date) {
        payments.push_back(currentPayment);
    }

    double totalAmount = 0;
    double maxPayment = 0;
    std::string topRecipient;

    // Calculate total and find maximum payment
    for (const auto& payment : payments) {
        totalAmount += payment.amount;
        if (payment.amount > maxPayment) {
            maxPayment = payment.amount;
            topRecipient = payment.firstName + " " + payment.lastName;
        }
    }

    // Display results
    std::cout << "\nTotal payments: $" << totalAmount << std::endl;
    std::cout << "Top recipient: " << topRecipient 
              << " with $" << maxPayment << std::endl;

    inputFile.close();
    return 0;
}
