# Access Specifiers in Inheritance

When a derived class inherits from a base class, the access level of the members in the base class depends on the type of inheritance (i.e., public, protected, or private inheritance).

## 1. Public Inheritance

In public inheritance:
- The `public` members of the base class remain `public` in the derived class.
- The `protected` members of the base class remain `protected` in the derived class.
- The `private` members of the base class are **not accessible** in the derived class.

### Example:

```cpp
class Base {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
};

class Derived : public Base {
public:
    void accessMembers() {
        publicVar = 10;    // Accessible: publicVar is public in Derived
        protectedVar = 20; // Accessible: protectedVar is protected in Derived
        // privateVar = 30; // Error: privateVar is not accessible in Derived
    }
};
```

## 2. Protected Inheritance

In protected inheritance:
- The `public` and `protected` members of the base class become `protected` in the derived class.
- The `private` members are **still inaccessible**.

### Example:

```cpp
class Base {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
};

class Derived : protected Base {
public:
    void accessMembers() {
        publicVar = 10;    // Accessible: publicVar is protected in Derived
        protectedVar = 20; // Accessible: protectedVar is protected in Derived
        // privateVar = 30; // Error: privateVar is not accessible in Derived
    }
};
```

## 3. Private Inheritance

In private inheritance:
- The `public` and `protected` members of the base class become `private` in the derived class.
- The `private` members are **still inaccessible**.

### Example:

```cpp
class Base {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
};

class Derived : private Base {
public:
    void accessMembers() {
        publicVar = 10;    // Accessible: publicVar is private in Derived
        protectedVar = 20; // Accessible: protectedVar is private in Derived 
        // privateVar = 30; // Error: privateVar is not accessible in Derived
    }
};
```

## 4. Access Specifiers Summary for Inheritance

| Inheritance Type       | Base Class Member Access in Derived Class |
|------------------------|------------------------------------------|
| **Public Inheritance** | Public → Public, Protected → Protected, Private → Inaccessible |
| **Protected Inheritance** | Public → Protected, Protected → Protected, Private → Inaccessible |
| **Private Inheritance** | Public → Private, Protected → Private, Private → Inaccessible |

Understanding these access specifiers is crucial for designing class hierarchies effectively and ensuring proper encapsulation in C++ programming.

