#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store each waste item (row of the CSV)
struct WasteItem {
    string name;
    string nameEs;     // Example: "Banana Peel"
    string category;  // Example: "Organic"
    string bin;       // Example: "Green"
};

int main() {
    vector<WasteItem> wasteList; // Vector to hold all waste items

    // Try to open the dataset file
    ifstream file("waste_items_dataset.csv");
    if (!file.is_open()) {
        cerr << "❌ Could not open dataset.\n";
        return 1;
    }

    string line;
    getline(file, line); // Skip the first line (header row)

    // Read each line of the CSV
    while (getline(file, line)) {
        stringstream ss(line);
        WasteItem item;

        // Read data separated by commas
        getline(ss, item.name, ',');
        getline(ss, item.nameEs, ',');
        getline(ss, item.category, ',');
        getline(ss, item.bin, ',');

        // Add the item to the vector
        wasteList.push_back(item);
    }

    // Ask the user for input
    string userInput;
    cout << "Enter the item you want to throw: ";
    getline(cin, userInput);

    // Convert user input to lowercase for case-insensitive search
    transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

    bool found = false; // Flag to track if item is found

    // Loop through each item in the dataset
    for (auto &item : wasteList) {
        // Create a lowercase version of the item name for comparison
        string nameLower = item.name;
        transform(nameLower.begin(), nameLower.end(), nameLower.begin(), ::tolower);

        // If user input is contained in the item name
        if (nameLower.find(userInput) != string::npos) {
            cout << "\n✅ Item found: " << item.name << "\n";
            cout << "Category: " << item.category << "\n";
            cout << "You should throw it in the " << item.category << " bin.\n";
            found = true;
            break;
        }
    }

    // If not found in the dataset
    if (!found)
        cout << "\n⚠️ Sorry, item not found in the database.\n";


    return 0;
}