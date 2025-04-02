#include <iostream>
using namespace std;

// Base class
class Character {
public:
    virtual void attack() { // Virtual function
        cout << "Character attacks in a generic way!\n";
    }
};

// Derived class 1
class Warrior : public Character {
public:
    void attack() override { // Overriding the base class function
        cout << "Warrior swings a sword!\n";
    }
};

// Derived class 2
class Mage : public Character {
public:
    void attack() override { // Overriding the base class function
        cout << "Mage casts a fireball!\n";
    }
};

int main() {
    Character* player1; // Base class pointer
    Warrior w;
    Mage m;

    player1 = &w;
    player1->attack();  // Output: Warrior swings a sword!

    player1 = &m;
    player1->attack();  // Output: Mage casts a fireball!

    return 0;
}

// Real-World Use Cases
// ✅ Game development – Different character behaviors.
// ✅ Graphics Rendering – Different shapes (Circle, Rectangle) override draw().
// ✅ AI Systems – Different AI bots have unique think() methods.
