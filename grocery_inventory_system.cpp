#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;

const int MAX_ITEMS = 100;
const string FILE_NAME = "products.txt";

string names[MAX_ITEMS];
double prices[MAX_ITEMS];
string units[MAX_ITEMS];
string productTypes[MAX_ITEMS];
int quantities[MAX_ITEMS];
int itemCount = 0;

map<string, string> predefinedTypes = {
    {"Dairy", "D"}, {"Vegetable", "V"}, {"Fruit", "F"},
    {"Grains", "G"}, {"Beverages", "B"}, {"Oils", "O"},
    {"Snacks", "S"}, {"Condiments", "C"}, {"Liquids", "L"},
    {"Paper Products", "P"}
};

map<string, int> thresholds = {
    {"Dairy", 10}, {"Vegetable", 5}, {"Fruit", 5}, {"Grains", 10},
    {"Beverages", 5}, {"Oils", 10}, {"Snacks", 5}, {"Condiments", 5},
    {"Liquids", 5}, {"Paper Products", 10}
};

vector<string> customUnits;

void saveProductsToFile() {
    ofstream outFile(FILE_NAME);
    if (!outFile) {
        cout << "Error saving products to file.\n";
        return;
    }

    outFile << itemCount << "\n";
    for (int i = 0; i < itemCount; i++) {
        outFile << names[i] << "," << prices[i] << "," << units[i] << ","
                << productTypes[i] << "," << quantities[i] << "\n";
    }
    outFile.close();
}

void loadProductsFromFile() {
    ifstream inFile(FILE_NAME);
    if (!inFile) return;

    inFile >> itemCount;
    inFile.ignore();

    for (int i = 0; i < itemCount; i++) {
        getline(inFile, names[i], ',');
        inFile >> prices[i];
        inFile.ignore();
        getline(inFile, units[i], ',');
        getline(inFile, productTypes[i], ',');
        inFile >> quantities[i];
        inFile.ignore();
    }
    inFile.close();
}

void displayProducts() {
    if (itemCount == 0) {
        cout << "No products in inventory.\n";
        return;
    }

    // Displaying the table header
    cout << "\n| Product ID | Name | Price | Unit  | Type | Quantity |\n";
    cout << "|------------|------|-------|-------|------|----------|\n";

    for (int i = 0; i < itemCount; i++) {
        cout << "| " << i + 1 << "          | " << names[i] << "  | " << prices[i] << "   | " 
             << units[i] << "  | " << productTypes[i] << "   | " << quantities[i] << "        |" << endl;

        // Checking if the quantity is below the threshold
        if (quantities[i] < thresholds[productTypes[i]]) {
            cout << "Warning: Low stock for this product!\n";
        }
    }
    cout << "\n";
}

void addProduct() {
    do {
        if (itemCount >= MAX_ITEMS) {
            cout << "Inventory is full. Cannot add more products.\n";
            return;
        }

        int productId = itemCount + 1;
        cout << "Product ID: " << productId << " has been assigned.\n";

        cout << "Enter product name: ";
        cin >> names[itemCount];

        cout << "Enter product price: ";
        cin >> prices[itemCount];

        cout << "Enter product unit (e.g., Bottle, Kilogram, Liter, Pack). You can also create your own unit: ";
        cin >> units[itemCount];

        if (find(customUnits.begin(), customUnits.end(), units[itemCount]) == customUnits.end()) {
            customUnits.push_back(units[itemCount]);
        }

        cout << "Enter the product type (e.g., Dairy, Vegetable). If not listed, you can create your own:\n";
        cout << "Existing types:\n";
        for (const auto& pair : predefinedTypes) {
            cout << pair.first << " (" << pair.second << ")\n";
        }

        string type;
        string letter;
        cin.ignore();
        getline(cin, type);

        // Check if input is a single letter (e.g., "D") and map to predefined type
        if (type.length() == 1) {
            for (const auto& pair : predefinedTypes) {
                if (pair.second == type) {
                    type = pair.first;  // Map the letter to the full name
                    break;
                }
            }
        }

        if (predefinedTypes.find(type) == predefinedTypes.end()) {
            cout << "Type not found. Creating a new type...\n";
            cout << "Enter a single letter to represent this new type: ";
            cin >> letter;
            predefinedTypes[type] = letter;

            cout << "Enter the low stock threshold for this type: ";
            int threshold;
            cin >> threshold;
            thresholds[type] = threshold;

            cout << "New type '" << type << "' added successfully.\n";
        }
        productTypes[itemCount] = type;

        cout << "Enter product quantity: ";
        cin >> quantities[itemCount];

        itemCount++;
        cout << "Product added successfully.\n";

        cout << "Do you want to repeat this task (add another product)? (Y/N): ";
        string repeatTask;
        cin >> repeatTask;
        if (repeatTask == "N" || repeatTask == "n") break;
    } while (true);

    cout << "Do you want to perform another task? (Y/N): ";
    string anotherTask;
    cin >> anotherTask;
    if (anotherTask == "N" || anotherTask == "n") {
        displayProducts(); // Show products only when no more tasks
        exit(0);
    }
}

void updateProduct() {
    do {
        int id;
        cout << "Enter product ID to update: ";
        cin >> id;

        if (id <= 0 || id > itemCount) {
            cout << "Product ID not found.\n";
            cout << "Do you want to update another product? (Y/N): ";
            string repeatTask;
            cin >> repeatTask;
            if (repeatTask == "N" || repeatTask == "n") break;
            else continue;
        }

        cout << "Updating product " << names[id - 1] << ":\n";

        cout << "Enter new name: ";
        cin >> names[id - 1];

        cout << "Enter new price: ";
        cin >> prices[id - 1];

        cout << "Enter new quantity: ";
        cin >> quantities[id - 1];

        cout << "Product updated successfully.\n";

        cout << "Do you want to repeat this task (update another product)? (Y/N): ";
        string repeatTask;
        cin >> repeatTask;
        if (repeatTask == "N" || repeatTask == "n") break;
    } while (true);

    cout << "Do you want to perform another task? (Y/N): ";
    string anotherTask;
    cin >> anotherTask;
    if (anotherTask == "N" || anotherTask == "n") {
        displayProducts(); // Show products only when no more tasks
        exit(0);
    }
}

void deleteProduct() {
    do {
        int id;
        cout << "Enter product ID to delete: ";
        cin >> id;

        if (id <= 0 || id > itemCount) {
            cout << "Product ID not found.\n";
            cout << "Do you want to delete another product? (Y/N): ";
            string repeatTask;
            cin >> repeatTask;
            if (repeatTask == "N" || repeatTask == "n") break;
            else continue;
        }

        for (int i = id - 1; i < itemCount - 1; i++) {
            names[i] = names[i + 1];
            prices[i] = prices[i + 1];
            units[i] = units[i + 1];
            productTypes[i] = productTypes[i + 1];
            quantities[i] = quantities[i + 1];
        }

        itemCount--;
        cout << "Product deleted successfully.\n";

        cout << "Do you want to repeat this task (delete another product)? (Y/N): ";
        string repeatTask;
        cin >> repeatTask;
        if (repeatTask == "N" || repeatTask == "n") break;
    } while (true);

    cout << "Do you want to perform another task? (Y/N): ";
    string anotherTask;
    cin >> anotherTask;
    if (anotherTask == "N" || anotherTask == "n") {
        displayProducts(); // Show products only when no more tasks
        exit(0);
    }
}

void searchProductByID() {
    do {
        int id;
        cout << "Enter product ID to search: ";
        cin >> id;

        if (id <= 0 || id > itemCount) {
            cout << "Product ID not found.\n";
            cout << "Do you want to search another product? (Y/N): ";
            string repeatTask;
            cin >> repeatTask;
            if (repeatTask == "N" || repeatTask == "n") break;
            else continue;
        }

        // Displaying the found product details
        cout << "Product ID: " << id << "\n";
        cout << "Name: " << names[id - 1] << "\n";
        cout << "Price: " << prices[id - 1] << "\n";
        cout << "Unit: " << units[id - 1] << "\n";
        cout << "Type: " << productTypes[id - 1] << "\n";
        cout << "Quantity: " << quantities[id - 1] << "\n";

        cout << "Do you want to search another product? (Y/N): ";
        string repeatTask;
        cin >> repeatTask;
        if (repeatTask == "N" || repeatTask == "n") break;
    } while (true);

    cout << "Do you want to perform another task? (Y/N): ";
    string anotherTask;
    cin >> anotherTask;
    if (anotherTask == "N" || anotherTask == "n") {
        cout << "Exiting program...\n";
        exit(0);
    }
}

int main() {
    loadProductsFromFile();
    while (true) {
        cout << "\nMain Menu:\n";
        cout << "1. Add Product\n";
        cout << "2. Update Product\n";
        cout << "3. Delete Product\n";
        cout << "4. Display Products\n";
        cout << "5. Search Product by ID\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                updateProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                displayProducts();
                break;
            case 5:
                searchProductByID();
                break;
            case 6:
                saveProductsToFile();
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

