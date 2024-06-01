#include <iostream>
using namespace std;

// Base class
class Animal {
protected:
    string species;

public:
    // Default constructor
    Animal() : species("Unknown") {}

    // Parameterized constructor
    Animal(string sp) : species(sp) {}

    // Function to display species
    void displaySpecies() {
        cout << "Species: " << species << endl;
    }
};

// Derived class
class Dog : public Animal {
private:
    string breed;

public:
    // Parameterized constructor
    Dog(string sp, string br) : Animal(sp), breed(br) {}

    // Function to display breed
    void displayBreed() {
        cout << "Breed: " << breed << endl;
    }

    // Function to display species and breed
    void displayInfo() {
        cout << "Species: " << species << ", Breed: " << breed << endl;
    }
};

int main() {
    Dog myDog("Canine", "Golden Retriever");

    // Accessing protected member through derived class
    myDog.displayInfo();

    // The following line would cause a compilation error because 'species' is protected in 'Animal'
    // cout << "Species: " << myDog.species << endl;

    return 0;
}
