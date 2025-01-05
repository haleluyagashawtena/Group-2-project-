# Inventory Management System

This is a simple inventory management system written in C++. It allows the user to add, update, delete, display, and search for products in an inventory. The inventory is limited to a maximum of 1000 products.

## Features

- **Add Product**: Add a new product to the inventory.
- **Update Product**: Update the details of an existing product.
- **Delete Product**: Delete a product from the inventory using its ID.
- **Display Products**: Display all products in the inventory.
- **Search Product by ID**: Search for a product in the inventory using its ID.

## Code Overview

The main components of the code include:

- **Product Structure**: Defines the structure of a product, including its ID, name, price, quantity, and type.
- **Global Variables**: 
  - `products[MAX_PRODUCTS]`: An array to store up to `MAX_PRODUCTS` number of products.
  - `productCount`: Tracks the number of products currently in the inventory.
- **Functions**: 
  - `addProduct()`: Adds a new product to the inventory.
  - `updateProduct()`: Updates the details of an existing product.
  - `deleteProduct()`: Deletes a product from the inventory.
  - `displayProducts()`: Displays all products in the inventory.
  - `searchProductByID()`: Searches for a product by its ID.

## How to Use

1. **Compile the Program**: Use a C++ compiler to compile the program.
   ```bash
   g++ -o inventory_management main.cpp
   ```
2. **Run the Program**: Execute the compiled program.
   ```bash
   ./inventory_management
   ```

3. **Menu Options**: The program displays a menu with the following options:
   1. Add Product
   2. Update Product
   3. Delete Product
   4. Display Products
   5. Search Product by ID
   6. Exit

4. **Choose an Option**: Enter the number corresponding to the desired action.

## Example Usage

Here's an example of how the program works:

```
Menu:
1. Add Product
2. Update Product
3. Delete Product
4. Display Products
5. Search Product by ID
6. Exit
Enter choice: 1
Enter product ID: 101
Enter product name: Apple
Enter product price: 0.99
Enter product quantity: 50
Enter product type: Fruits
Product added successfully!
```

## Limitations

- The program is limited to a maximum of 1000 products.
- The user must enter valid data types for each input (e.g., integers for IDs and quantities, floats for prices).

## Future Improvements

- Implement file I/O to save and load inventory data from a file.
- Add input validation to handle incorrect data types.
- Enhance the user interface for a better user experience.

## License

This project is open-source and available under the [MIT License](https://opensource.org/licenses/MIT).

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

   








