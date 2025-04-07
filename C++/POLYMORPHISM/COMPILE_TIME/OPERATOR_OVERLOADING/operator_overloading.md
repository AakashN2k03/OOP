# C++ Operator Overloading

## What is Operator Overloading?
In C++, operator overloading means giving additional meaning to standard operators (like +, -, *, etc.) when they are used with objects.

👉 In simple terms, it allows you to use operators with your own custom classes, just like how you use them with built-in data types.

## 📌 Why Use Operator Overloading?
Let's say you create a Complex class to represent complex numbers like 3 + 2i.
Normally, if you do obj1 + obj2, it won't work. But with operator overloading, you can define how + should behave for your object.

✅ This makes your code look cleaner and more natural.

## ✍️ Syntax of Operator Overloading
```cpp
return_type operator symbol (parameters) {
    // define what the operator should do
}
```

Example:
```cpp
Complex operator + (Complex obj);
```

This means: "I'm overloading the + operator for the Complex class".

## ✅ What Operators Can Be Overloaded?
Almost all operators can be overloaded, like:

- +, -, *, /, % (arithmetic)
- ==, !=, <, > (comparison)
- [], (), ->, =
- ++, -- (increment/decrement)
- <<, >> (stream insertion/extraction)

## ❌ But you cannot overload:
- :: (scope resolution)
- . (member access)
- .* (pointer-to-member)
- sizeof, typeid

## 📝 Summary
- Operator Overloading allows you to define how operators work with your custom objects.
- Use it to make your classes behave like built-in types.
- Improves code readability and makes classes more intuitive.
