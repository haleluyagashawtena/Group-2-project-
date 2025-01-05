#include <iostream>     // For input-output operations
#include <vector>       // For using the vector container
#include <string>       // For using the string class
#include <map>          // For using the map container
#include <fstream>      // For file input-output operations
#include <algorithm>    // For using algorithms like find
using namespace std;

// Constants
const int MAX_ITEMS = 100;  // Max items in inventory
const string FILE_NAME = "products.txt";  // File to save/load products

// Global variables
string names[MAX_ITEMS], units[MAX_ITEMS], productTypes[MAX_ITEMS];
double prices[MAX_ITEMS];
int quantities[MAX_ITEMS], itemCount = 0;  // Total items in inventory

// Predefined product types with shorthand
map<string, string> predefinedTypes = {
    {"Dairy", "D"}, {"Vegetable", "V"}, {"Fruit", "F"}, {"Grains", "G"},
    {"Beverages", "B"}, {"Oils", "O"}, {"Snacks", "S"}, {"Condiments", "C"}
};

// Stock warning thresholds
map<string, int> thresholds = {
    {"Dairy", 10}, {"Vegetable", 5}, {"Fruit", 5}, {"Grains", 10}
};

// Custom user-defined units
vector<string> customUnits;

// Function to save products to a file
void saveProductsToFile() {
    ofstream outFile(FILE_NAME);  // Create an output file stream to save products
    if (!outFile) {  // Check if file is successfully opened
        cout << "Error saving products.\n";
        return;
    }
    outFile << itemCount << "\n";  // Write the number of items in inventory
    for (int i = 0; i < itemCount; i++) {  // Loop through all items and save their details
        outFile << names[i] << "," << prices[i] << "," << units[i] << ","
                << productTypes[i] << "," << quantities[i] << "\n";
    }
    outFile.close();  // Close the file
}

// Function to load products from a file
void loadProductsFromFile() {
    ifstream inFile(FILE_NAME);  // Create an input file stream to load products
    if (!inFile) return;  // If file does not exist, return
    inFile >> itemCount;  // Read the number of items in inventory
    inFile.ignore();  // Ignore the newline character after itemCount
    for (int i = 0; i < itemCount; i++) {  // Loop to read each product's details
        getline(inFile, names[i], ',');  // Read name
        inFile >> prices[i];  // Read price
        inFile.ignore();  // Ignore comma
        getline(inFile, units[i], ',');  // Read unit
        getline(inFile, productTypes[i], ',');  // Read product type
        inFile >> quantities[i];  // Read quantity
        inFile.ignore();  // Ignore newline character
    }
    inFile.close();  // Close the file
}

// Function to display all products in a table
void displayProducts() {
    if (itemCount == 0) {  // If no items, print message
        cout << "Inventory is empty.\n";
        return;
    }
    // Print table header
    cout << "\n| ID | Name | Price | Unit | Type | Qty |\n";
    for (int i = 0; i < itemCount; i++) {  // Loop through all items to display their details
        cout << "| " << i + 1 << " | " << names[i] << " | " << prices[i] << " | "
             << units[i] << " | " << productTypes[i] << " | " << quantities[i] << " |\n";
        if (quantities[i] < thresholds[productTypes[i]]) {  // Check if stock is low
            cout << "Warning: Low stock!\n";
        }
    }
}

// Add new product
void addProduct() {
    if (itemCount >= MAX_ITEMS) {  // Check if inventory is full
        cout << "Inventory is full.\n";
        return;
    }
    cout << "Enter product details:\n";
    cout << "Name: "; cin >> names[itemCount];  // Input product name
    cout << "Price: "; cin >> prices[itemCount];  // Input product price
    cout << "Unit (e.g., kg, liter): "; cin >> units[itemCount];  // Input product unit
    customUnits.push_back(units[itemCount]);  // Add unit to custom units list

    cout << "Type (e.g., Dairy, Vegetable): ";
    string type; cin.ignore(); getline(cin, type);  // Input product type
    if (predefinedTypes.find(type) == predefinedTypes.end()) {  // Check if type is new
        string shortType;
        cout << "New type detected. Enter shorthand: "; cin >> shortType;  // Input shorthand for new type
        predefinedTypes[type] = shortType;  // Add new type to predefined types
        cout << "Enter stock threshold: "; cin >> thresholds[type];  // Input stock threshold
    }
    productTypes[itemCount] = type;  // Assign product type
    cout << "Quantity: "; cin >> quantities[itemCount];  // Input product quantity
    itemCount++;  // Increment item count
    cout << "Product added successfully.\n";  // Success message
}

// Update existing product
void updateProduct() {
    int id;
    cout << "Enter product ID to update: "; cin >> id;  // Input product ID to update
    if (id <= 0 || id > itemCount) {  // Check if ID is valid
        cout << "Invalid ID.\n";
        return;
    }
    cout << "Updating product " << names[id - 1] << ":\n";
    cout << "New name: "; cin >> names[id - 1];  // Input new name
    cout << "New price: "; cin >> prices[id - 1];  // Input new price
    cout << "New quantity: "; cin >> quantities[id - 1];  // Input new quantity
    cout << "Product updated successfully.\n";  // Success message
}

// Delete product by ID
void deleteProduct() {
    int id;
    cout << "Enter product ID to delete: "; cin >> id;  // Input product ID to delete
    if (id <= 0 || id > itemCount) {  // Check if ID is valid
        cout << "Invalid ID.\n";
        return;
    }
    for (int i = id - 1; i < itemCount - 1; i++) {  // Shift elements to delete the product
        names[i] = names[i + 1];
        prices[i] = prices[i + 1];
        units[i] = units[i + 1];
        productTypes[i] = productTypes[i + 1];
        quantities[i] = quantities[i + 1];
    }
    itemCount--;  // Decrement item count
    cout << "Product deleted successfully.\n";  // Success message
}

// Search product by ID
void searchProductByID() {
    int id;
    cout << "Enter product ID to search: "; cin >> id;  // Input product ID to search
    if (id <= 0 || id > itemCount) {  // Check if ID is valid
        cout << "Invalid ID.\n";
        return;
    }
    // Display product details
    cout << "Product details:\n";
    cout << "Name: " << names[id - 1] << "\n";
    cout << "Price: " << prices[id - 1] << "\n";
    cout << "Unit: " << units[id - 1] << "\n";
    cout << "Type: " << productTypes[id - 1] << "\n";
    cout << "Quantity: " << quantities[id - 1] << "\n";
}

// Main menu and program loop
int main() {
    loadProductsFromFile();  // Load products from file at the start
    while (true) {  // Infinite loop for the main menu
        cout << "\nMenu:\n";
        cout << "1. Add Product\n";
        cout << "2. Update Product\n";
        cout << "3. Delete Product\n";
        cout << "4. Display Products\n";
        cout << "5. Search Product by ID\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        int choice; cin >> choice;  // Input user's choice
        switch (choice) {  // Switch case for each menu option
            case 1: addProduct(); break;
            case 2: updateProduct(); break;
            case 3: deleteProduct(); break;
            case 4: displayProducts(); break;
            case 5: searchProductByID(); break;
            case 6: saveProductsToFile(); return 0;  // Save products and exit program
            default: cout << "Invalid choice.\n";  // Invalid choice message
        }
    }
}
