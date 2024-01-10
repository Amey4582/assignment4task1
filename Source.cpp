#include <iostream>
#include <vector>

struct Product {
    int id;
    std::string name;
    double price;
};

std::vector<Product> inventory;

void addProduct(int id, const std::string& name, double price) {
    Product newProduct = { id, name, price };
    inventory.push_back(newProduct);
}

void removeProduct(int id) {
    auto it = std::remove_if(inventory.begin(), inventory.end(),
        [id](const Product& p) { return p.id == id; });
    inventory.erase(it, inventory.end());
}

int main() {
    // Example Usage
    addProduct(1, "LAHORI CHANEY", 999.99);
    addProduct(2, "PODINEY WALA NAAN", 49.99);
    removeProduct(1);  // Remove product with ID 1

    // Display the remaining inventory
    for (const auto& product : inventory) {
        std::cout << "ID: " << product.id << ", Name: " << product.name << ", Price: $" << product.price << "\n";
    }

    return 0;
}
