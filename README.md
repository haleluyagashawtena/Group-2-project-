# Inventory Management System

This program is a simple inventory management system that allows users to add, update, delete, search, and display products in an inventory. The data is stored in a file (products.txt) and can be loaded and saved between program runs. The program allows for customization of product types, units, and stock thresholds.

## Features
1. Add Product: Users can add a new product to the inventory, specifying its name, price, unit, type, and quantity.
2. Update Product: Users can update an existing product's details such as name, price, and quantity.
3. Delete Product: Users can delete a product from the inventory by its ID.
4. Display Products: Users can view all products in the inventory along with their details (ID, name, price, unit, type, and quantity). Low-stock products are flagged with a warning.
5. Search Product by ID: Users can search for a product by its unique ID and view its details.
6. Custom Types and Units: Users can create their own product types and units that are not predefined in the system.
7. Threshold Warning: Products with quantities below their predefined threshold will trigger a low-stock warning.

## How It Works
- Products are stored in arrays with a limit of MAX_ITEMS = 100 items.
- Each product has the following attributes:
  - Name: The name of the product.
  - Price: The price of the product.
  - Unit: The unit of measurement (e.g., Bottle, Kilogram, Liter).
  - Type: The category of the product (e.g., Dairy, Fruit, Grains).
  - Quantity: The available quantity of the product.
- Data is stored in the file products.txt, which is loaded at the start of the program and saved at the end.

## Predefined Product Types
The program comes with a set of predefined product types:
- Dairy (D)
- Vegetable (V)
- Fruit (F)
- Grains (G)
- Beverages (B)
- Oils (O)
- Snacks (S)
- Condiments (C)
- Liquids (L)
- Paper Products (P)

Custom product types can also be added by the user with a corresponding letter representation.

## Data Storage
The inventory data is stored in the products.txt file in the following format:
<item_count>
<name>,<price>,<unit>,<type>,<quantity>

- The first line contains the number of items in the inventory.
- Each subsequent line contains the details of a product, separated by commas.

## Main Menu Options
When the program is running, the user is presented with a main menu with the following options:

1. Add Product: Allows the user to add a new product.
2. Update Product: Allows the user to update an existing product by entering its ID.
3. Delete Product: Allows the user to delete a product by entering its ID.
4. Display Products: Shows all products in the inventory.
5. Search Product by ID: Allows the user to search for a product by its ID and view its details.
6. Exit: Saves the data to products.txt and exits the program.

## Example Usage
### Adding a Product:
Enter product name: Milk
Enter product price: 2.5
Enter product unit (e.g., Bottle, Kilogram, Liter, Pack): Liter
Enter the product type (e.g., Dairy, Vegetable): Dairy
Enter product quantity: 50
Product added successfully.

### Updating a Product:
Enter product ID to update: 1
Updating product Milk:
Enter new name: Soy Milk
Enter new price: 3.0
Enter new quantity: 45
Product updated successfully.

### Deleting a Product:
Enter product ID to delete: 2
Product deleted successfully.

### Displaying Products:
| Product ID | Name       | Price | Unit   | Type | Quantity |
|------------|------------|-------|--------|------|----------|
| 1          | Soy Milk   | 3.0   | Liter  | D    | 45       |
| 2          | Apple      | 1.0   | Kilogram| F    | 30       |

### Searching for a Product:
Enter product ID to search: 1
Product ID: 1
Name: Soy Milk
Price: 3.0
Unit: Liter
Type: Dairy
Quantity: 45

## File Management
- Loading: The program automatically loads data from products.txt when it starts.
- Saving: Any changes made during the session are saved to products.txt when the program exits.


## Conclusion
This program provides a basic inventory management system that can be expanded further based on specific needs. It supports essential operations such as adding, updating, deleting, and searching for products. Additionally, it supports customization of product types, units, and stock thresholds.

#here is the code
```mermaid

graph TD
    A[Start] --> B[Load Products from File]
    B --> C{Menu}
    C -->|Add Product| D[Add Product Function]
    C -->|Update Product| E[Update Product Function]
    C -->|Delete Product| F[Delete Product Function]
    C -->|Display Products| G[Display Products Function]
    C -->|Search Product by ID| H[Search Product by ID Function]
    C -->|Exit| I[Save Products to File and Exit]
    
    D --> J[Input Product Name]
    J --> K[Input Product Price]
    K --> L[Input Unit Type]
    L --> M[Check Custom Unit]
    M --> N[Input Product Type]
    N --> O[Add Product to List]
    O --> P[Ask if Repeat Task]
    P -->|Yes| D
    P -->|No| C

    E --> Q[Input Product ID to Update]
    Q --> R[Check Product ID Validity]
    R -->|Valid| S[Update Product Info]
    S --> T[Ask if Repeat Task]
    T -->|Yes| E
    T -->|No| C

    F --> U[Input Product ID to Delete]
    U --> V[Check Product ID Validity]
    V -->|Valid| W[Delete Product]
    W --> X[Ask if Repeat Task]
    X -->|Yes| F
    X -->|No| C

    G --> Y[Display Product List]
    Y --> Z[Check Quantity Against Threshold]
    Z --> AA[Warn if Low Stock]
    AA --> AB[Return to Menu]

    H --> AC[Input Product ID to Search]
    AC --> AD[Check Product ID Validity]
    AD -->|Valid| AE[Display Product Info]
    AE --> AF[Ask if Repeat Task]
    AF -->|Yes| H
    AF -->|No| C

    I --> AG[Exit Program]
    AG --> A


   








