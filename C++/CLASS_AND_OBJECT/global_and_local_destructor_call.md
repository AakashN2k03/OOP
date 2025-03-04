# When Does the Destructor Get Called? 🧹

## Overview
This README explores the different scenarios of destructor calls in C++, focusing on local (automatic) and global/static objects.

## Cases of Destructor Calls

### Case 1: Local (Automatic) Objects 🏠
- Objects created inside `main()` without `new`
- Destructor is called when `main()` reaches `}` (before `main()` fully exits)

#### Example: Local Object
```cpp
#include <iostream>
using namespace std;

class Demo {
public:
    Demo() { 
        cout << "Constructor called\n"; 
    }
    
    ~Demo() { 
        cout << "Destructor called\n"; 
    }
};

int main() {
    Demo obj; // Local object
    cout << "Inside main()\n";
    return 0; 
} 
// Output:
// Constructor called
// Inside main()
// Destructor called <-- Called at } inside main()
```

**Key Points:**
- Memory is cleared when `main()` reaches `}`
- Destructor called before `main()` fully exits

### Case 2: Global & Static Objects 🌍
- Objects exist before `main()` starts
- Live until `main()` fully exits
- Destructor called after `main()` exits, right before program termination

#### Example: Global Object
```cpp
#include <iostream>
using namespace std;

class Demo {
public:
    Demo() { 
        cout << "Constructor called\n"; 
    }
    
    ~Demo() { 
        cout << "Destructor called\n"; 
    }
};

Demo globalObj; // Global object

int main() {
    cout << "Inside main()\n";
    return 0;
} 
// Output:
// Constructor called (for globalObj)
// Inside main()
// Destructor called <-- Called after main() exits
```

**Key Points:**
- Memory is cleared only after `main()` completely finishes
- Destructor called just before program termination

## Comparison Table

| Object Type | Destructor Called | Memory Cleared |
|------------|-------------------|----------------|
| Local Object (inside `main()`) | When `main()` reaches `}` | Before `main()` fully exits |
| Global/Static Object | After `main()` exits | Before program terminates |

## Simple Explanation
- **Local objects**: Cleaned up when `main()` reaches `}`, while `main()` is still running
- **Global/Static objects**: Cleaned up after `main()` finishes, just before the program stops

## Best Practices
- Be aware of object lifecycle and destructor call timing
- Understand the difference between local and global object destruction
- Use destructors for proper resource management and cleanup

## Conclusion
Understanding when destructors are called is crucial for managing memory and resources in C++ programs.
