# V-Table and V-Pointer

## 🧩 What is V-Table and V-Pointer?

| Term | Meaning |
|------|---------|
| V-Table | A hidden table created by the compiler that holds function pointers to virtual functions. |
| V-Pointer (vptr) | A hidden pointer inside each object that points to its class's V-Table. |

## 🧠 Why is it needed?

To implement runtime polymorphism using virtual functions. When we call a virtual function using a base class pointer, the compiler doesn't decide which function to run — it defers that decision to runtime. That's where V-Table and V-Pointer come in.

## 🔄 Simple Example

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() { cout << "Animal sound\n"; }
};

class Dog : public Animal {
public:
    void makeSound() override { cout << "Dog barks\n"; }
};
```

Now let's see what happens when you run:

```cpp
Animal* a;
Dog d;
a = &d;
a->makeSound(); // Which function should run? 🤔
```

## 🔬 Behind the Scenes – V-Table & V-Pointer

Here's what the compiler does internally:

### 🔸 Step 1: Create V-Tables

Compiler creates a V-Table for each class with virtual functions.

```
V-Table (Animal)
------------------
| makeSound() --> Animal::makeSound()

V-Table (Dog)
------------------
| makeSound() --> Dog::makeSound()
```

### 🔸 Step 2: Add V-Pointer to Objects

Each object of a class with virtual functions secretly gets a V-Pointer (vptr) pointing to its class's V-Table.

```
Object: d (of Dog)
----------------------
| vptr --> points to Dog's V-Table
```

### 🔸 Step 3: Function Call via V-Pointer

When you call `a->makeSound();`, even though `a` is of type `Animal*`, the vptr in the Dog object points to Dog's V-Table. So:

🔁 At runtime, it goes through:

```
a (Animal*) ➝ points to d (Dog object) ➝ vptr ➝ Dog's V-Table ➝ Dog::makeSound()
```

✅ Result: Dog barks

## 📊 Visual Diagram

```
┌────────────┐
│ Animal     │
│ V-Table    │
├────────────┤
│ makeSound ─┼────────────┐
└────────────┘            │
                          ▼
                Animal::makeSound()

┌────────────┐
│ Dog        │
│ V-Table    │
├────────────┤
│ makeSound ─┼────────────┐
└────────────┘            │
                          ▼
                Dog::makeSound()

┌────────────┐
│ Object d   │
│ (Dog)      │
├────────────┤
│ vptr ──────┼────────────> Points to Dog's V-Table
└────────────┘
```

## Is V-Table Created Per Class?

Yes! 🎯

## Real Explanation:

Let's say you have:

```cpp
class Animal {
public:
    virtual void makeSound();
};

class Dog : public Animal {
public:
    void makeSound() override;
};

class Cat : public Animal {
public:
    void makeSound() override;
};
```

Then what happens?

| Class | V-Table Created? | Contains |
|-------|------------------|----------|
| Animal | ✅ Yes | Pointer to Animal::makeSound() |
| Dog | ✅ Yes | Pointer to Dog::makeSound() |
| Cat | ✅ Yes | Pointer to Cat::makeSound() |

Even though makeSound() exists in all of them, each class has its own V-Table with the correct function pointer.

## ✅ Summary

| Feature | Description |
|---------|-------------|
| V-Table | A table storing function pointers to virtual functions for each class. |
| V-Pointer | A hidden pointer in each object pointing to the class's V-Table. |
| Purpose | Enables runtime polymorphism (dynamic function dispatch). |
| Created By | The compiler automatically. |
| When Used? | When calling virtual functions through base class pointers or references. |
