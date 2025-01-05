 # Inventory Management System

This program is a simple inventory management system that allows users to add, update, delete, search, and display products in an inventory. The data is stored in a file (`products.txt`) and can be loaded and saved between program runs. The program allows for customization of product types, units, and stock thresholds.

## Features
1. **Add Product**: Users can add a new product to the inventory, specifying its name, price, unit, type, and quantity.
2. **Update Product**: Users can update an existing product's details such as name, price, and quantity.
3. **Delete Product**: Users can delete a product from the inventory by its ID.
4. **Display Products**: Users can view all products in the inventory along with their details (ID, name, price, unit, type, and quantity). Low-stock products are flagged with a warning.
5. **Search Product by ID**: Users can search for a product by its unique ID and view its details.
6. **Custom Types and Units**: Users can create their own product types and units that are not predefined in the system.
7. **Threshold Warning**: Products with quantities below their predefined threshold will trigger a low-stock warning.

## How It Works
- Products are stored in arrays with a limit of `MAX_ITEMS = 100` items.
- Each product has the following attributes:
  - **Name**: The name of the product.
  - **Price**: The price of the product.
  - **Unit**: The unit of measurement (e.g., Bottle, Kilogram, Liter).
  - **Type**: The category of the product (e.g., Dairy, Fruit, Grains).
  - **Quantity**: The available quantity of the product.
- Data is stored in the file `products.txt`, which is loaded at the start of the program and saved at the end.

## Predefined Product Types
The program comes with a set of predefined product types:
- **Dairy (D)**
- **Vegetable (V)**
- **Fruit (F)**
- **Grains (G)**
- **Beverages (B)**
- **Oils (O)**
- **Snacks (S)**
- **Condiments (C)**
- **Liquids (L)**
- **Paper Products (P)**

Custom product types can also be added by the user with a corresponding letter representation.

## Data Storage
The inventory data is stored in the `products.txt` file in the following format:
```
<item_count>
<name>,<price>,<unit>,<type>,<quantity>
```

- The first line contains the number of items in the inventory.
- Each subsequent line contains the details of a product, separated by commas.

## Main Menu Options
When the program is running, the user is presented with a main menu with the following options:

1. **Add Product**: Allows the user to add a new product.
2. **Update Product**: Allows the user to update an existing product by entering its ID.
3. **Delete Product**: Allows the user to delete a product by entering its ID.
4. **Display Products**: Shows all products in the inventory.
5. **Search Product by ID**: Allows the user to search for a product by its ID and view its details.
6. **Exit**: Saves the data to `products.txt` and exits the program.

## Example Usage
### Adding a Product:
```
Enter product name: Milk
Enter product price: 2.5
Enter product unit (e.g., Bottle, Kilogram, Liter, Pack): Liter
Enter the product type (e.g., Dairy, Vegetable): Dairy
Enter product quantity: 50
Product added successfully.
```

### Updating a Product:
```
Enter product ID to update: 1
Updating product Milk:
Enter new name: Soy Milk
Enter new price: 3.0
Enter new quantity: 45
Product updated successfully.
```

### Deleting a Product:
```
Enter product ID to delete: 2
Product deleted successfully.
```

### Displaying Products:
```
| Product ID | Name       | Price | Unit   | Type | Quantity |
|------------|------------|-------|--------|------|----------|
| 1          | Soy Milk   | 3.0   | Liter  | D    | 45       |
| 2          | Apple      | 1.0   | Kilogram| F    | 30       |
```

### Searching for a Product:
```
Enter product ID to search: 1
Product ID: 1
Name: Soy Milk
Price: 3.0
Unit: Liter
Type: Dairy
Quantity: 45
```

## File Management
- **Loading**: The program automatically loads data from `products.txt` when it starts.
- **Saving**: Any changes made during the session are saved to `products.txt` when the program exits.

## Conclusion
This program provides a basic inventory management system that can be expanded further based on specific needs. It supports essential operations such as adding, updating, deleting, and searching for products. Additionally, it supports customization of product types, units, and stock thresholds.
#here is the code
```mermaid

graph TD
    A[Main Menu] --> B1[Add Product]
    A --> B2[Update Product]
    A --> B3[Delete Product]
    A --> B4[Display Products]
    A --> B5[Search Product by ID]
    A --> B6[Exit]
    
    B1 -->|Product ID: Assigned| C1[Enter Product Name]
    C1 --> C2[Enter Product Price]
    C2 --> C3[Enter Product Unit]
    C3 --> C4[Enter Product Type]
    C4 --> C5[New Type?]
    C5 -->|Yes| C6[Create New Type]
    C5 -->|No| C7[Select Existing Type]
    C6 --> C7
    C7 --> C8[Enter Product Quantity]
    C8 --> C9{Add Another Product?}
    C9 -->|Yes| B1
    C9 -->|No| D[Display Products]
    
    B2 -->|Enter Product ID| E1[Check Valid ID]
    E1 -->|Valid ID| E2[Enter New Name]
    E2 --> E3[Enter New Price]
    E3 --> E4[Enter New Quantity]
    E4 --> E5{Update Another Product?}
    E5 -->|Yes| B2
    E5 -->|No| D[Display Products]
    E1 -->|Invalid ID| E6{Update Another Product?}
    E6 -->|Yes| B2
    E6 -->|No| D[Display Products]
    
    B3 -->|Enter Product ID| F1[Check Valid ID]
    F1 -->|Valid ID| F2[Delete Product]
    F2 --> F3{Delete Another Product?}
    F3 -->|Yes| B3
    F3 -->|No| D[Display Products]
    F1 -->|Invalid ID| F4{Delete Another Product?}
    F4 -->|Yes| B3
    F4 -->|No| D[Display Products]
    
    B4 -->|Display All Products| G[Show Products]
    
    B5 -->|Enter Product ID| H1[Check Valid ID]
    H1 -->|Valid ID| H2[Show Product Details]
    H2 --> H3{Search Another Product?}
    H3 -->|Yes| B5
    H3 -->|No| I[Perform Another Task?]
    H1 -->|Invalid ID| H4{Search Another Product?}
    H4 -->|Yes| B5
    H4 -->|No| I[Perform Another Task?]
    
    B6 --> J[Save Products To File]
    J --> K[Exiting Program]
    
    I -->|Yes| A
    I -->|No| K[Exiting Program]

   








