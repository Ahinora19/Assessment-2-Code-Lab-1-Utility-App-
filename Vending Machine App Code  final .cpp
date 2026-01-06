#include <iostream> // For input and output
#include <iomanip> // For formatting output (setprecision)
#include <map> // For map container
#include <string> // For string data type
using namespace std;

// Structure to store item details
struct Item {
string name; // Item name
double price; // Item price
};

// Function to display vending machine menu
void displayMenu(const map<int, Item>& items) {
cout << "\n--- Vending Machine ---\n";
for (const auto& pair : items) {
cout << pair.first << ". "
<< pair.second.name << " - $"
<< fixed << setprecision(2)
<< pair.second.price << endl;
}
cout << "0. Exit\n"; // Option to exit
}

int main() {
// Store vending machine items
map<int, Item> items = {
{1, {"Soda", 1.50}},
{2, {"Chips", 1.00}},
{3, {"Candy", 0.75}},
{4, {"Water", 1.25}}
};

int choice; // User's menu choice
double moneyInserted; // Money inserted by user

// Loop until user exits
while (true) {
displayMenu(items); // Show menu

cout << "\nSelect an item: ";
cin >> choice; // Read user choice

// Exit condition
if (choice == 0) {
cout << "Thank you for using the vending machine.\n";
break;
}

// Check for invalid selection
if (items.find(choice) == items.end()) {
cout << "Invalid selection. Please try again.\n";
continue;
}

// Get selected item
Item selectedItem = items[choice];
cout << "Selected: " << selectedItem.name
<< " ($" << selectedItem.price << ")\n";

// Ask user to insert money
cout << "Insert money: $";
cin >> moneyInserted;

// Check if money is enough
if (moneyInserted < selectedItem.price) {
cout << "Insufficient funds. Money refunded: $"
<< fixed << setprecision(2)
<< moneyInserted << endl;
continue;
}

// Calculate change
double change = moneyInserted - selectedItem.price;

// Dispense item
cout << "Dispensing " << selectedItem.name << "...\n";

// Return change if any
if (change > 0) {
cout << "Returning change: $"
<< fixed << setprecision(2)
<< change << endl;
}

cout << "Enjoy!\n";
}

return 0; // End of program
}