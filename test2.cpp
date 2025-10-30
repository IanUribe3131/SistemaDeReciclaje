#include <iostream>
#include <string>
using namespace std;

// Base class for all types of waste
class Waste {
public:
    virtual string getBin() = 0; // Pure virtual function (must be implemented by child classes)
};

// Child classes for each waste type
class Organic : public Waste {
public:
    string getBin() override { return "Green (Organic) bin"; }
};

class Plastic : public Waste {
public:
    string getBin() override { return "Yellow (Plastic) bin"; }
};

class Metal : public Waste {
public:
    string getBin() override { return "Gray (Metal) bin"; }
};

class Glass : public Waste {
public:
    string getBin() override { return "Blue (Glass) bin"; }
};

class Paper : public Waste {
public:
    string getBin() override { return "Blue (Paper) bin"; }
};

int main() {
    cout << "♻️ Let's figure out where to throw your trash!\n";

    // Declare variables for user answers
    char organicQ, recyclableQ, metallicQ, glassQ;

    // Step 1: Check if it's organic
    cout << "Is it biodegradable (like food, fruit, or leaves)? (y/n): ";
    cin >> organicQ;

    if (organicQ == 'y' || organicQ == 'Y') {
        Organic o;
        cout << "You should throw it in the " << o.getBin() << ".\n";
        return 0; // End program early because we found the answer
    }

    // Step 2: Check if it's recyclable
    cout << "Is it recyclable (plastic, metal, glass, paper)? (y/n): ";
    cin >> recyclableQ;

    if (recyclableQ == 'y' || recyclableQ == 'Y') {
        // Step 3: Narrow down the material type
        cout << "Is it metal? (y/n): ";
        cin >> metallicQ;

        if (metallicQ == 'y' || metallicQ == 'Y') {
            Metal m;
            cout << "You should throw it in the " << m.getBin() << ".\n";
            return 0;
        }

        cout << "Is it glass? (y/n): ";
        cin >> glassQ;

        if (glassQ == 'y' || glassQ == 'Y') {
            Glass g;
            cout << "You should throw it in the " << g.getBin() << ".\n";
            return 0;
        }

        // If it's recyclable but not metal or glass, assume paper
        Paper p;
        cout << "You should throw it in the " << p.getBin() << ".\n";
        return 0;
    }

    // Step 4: Default option → assume plastic
    Plastic pl;
    cout << "You should throw it in the " << pl.getBin() << ".\n";
}
