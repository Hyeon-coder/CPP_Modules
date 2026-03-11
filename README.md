# CPP Modules

![Language](https://img.shields.io/badge/Language-C%2B%2B98-blue)
![School](https://img.shields.io/badge/School-Hive%20Helsinki-green)
![Type](https://img.shields.io/badge/Type-OOP-orange)
![Status](https://img.shields.io/badge/Status-In%20Progress-yellow)

A progressive C++98 learning series at [Hive Helsinki](https://www.hive.fi/) (42 Network). Starting from a C background, each module introduces core OOP concepts step by step — all under the **C++98 standard** (no `auto`, `nullptr`, range-for, or lambdas).

---

## Module Overview

| Module | Topic | Key Concepts | Status |
|--------|-------|-------------|--------|
| **00** | Basics | Namespaces, classes, member functions, stdio streams, initialization lists | ✅ |
| **01** | Memory & References | `new`/`delete`, references, pointers to members, `switch` | ✅ |
| **02** | Ad-hoc Polymorphism | Orthodox Canonical Form, operator overloading | ✅ |
| **03** | Inheritance | Class inheritance, diamond problem | ✅ |
| **04** | Polymorphism | Subtype polymorphism, abstract classes, interfaces | ✅ |
| **05** | Exceptions | `try`/`catch`, custom exception classes | ✅ |
| **06** | C++ Casts | `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast` | 🔜 |
| **07** | Templates | Function templates, class templates | 🔜 |
| **08** | STL Containers | `vector`, `list`, `map`, `stack`, iterators, algorithms | 🔜 |
| **09** | STL Advanced | Advanced containers, merge sort, Ford-Johnson algorithm | 🔜 |

---

## Orthodox Canonical Form (OCF)

A recurring pattern throughout the modules — every class must implement these four:

```cpp
class Sample {
public:
    Sample();                              // Default constructor
    Sample(const Sample& other);           // Copy constructor
    Sample& operator=(const Sample& rhs);  // Copy assignment operator
    ~Sample();                             // Destructor
};

// Copy constructor — deep copy
Sample::Sample(const Sample& other) {
    _data = new int(*other._data);  // Deep copy, not pointer copy
}

// Copy assignment — deep copy + self-assignment check
Sample& Sample::operator=(const Sample& rhs) {
    if (this != &rhs) {
        delete _data;
        _data = new int(*rhs._data);
    }
    return *this;
}
```

> Without deep copy, pointer members cause **double free** — the copy and original both try to free the same memory.

---

## Diamond Inheritance Problem

Encountered in Modules 03/04:

```
        ┌───────────┐
        │   Animal   │
        └─────┬─────┘
         ╱         ╲
  ┌─────┴─────┐  ┌──┴──────────┐
  │    Cat     │  │    Dog      │
  └─────┬─────┘  └──┬──────────┘
         ╲         ╱
     ┌────┴───┴────┐
     │   CatDog    │   ← Ambiguity: which Animal?
     └─────────────┘

  Solution: virtual inheritance
  class Cat : virtual public Animal {};
  class Dog : virtual public Animal {};
  → CatDog gets a single shared Animal base
```

---

## Build & Run

Each module contains independent exercises with their own Makefile.

```bash
git clone https://github.com/Hyeon-coder/CPP_Modules.git
cd CPP_Modules

# Build a specific module/exercise
cd Module_0/ex00
make
./megaphone

# Clean
make clean    # Remove object files
make fclean   # Remove object files and binary
make re       # Rebuild from scratch
```

---

## Key Challenges & What I Learned

### 1. Working Within C++98 Constraints
No `auto`, `nullptr`, range-for, or lambdas. Writing verbose code felt frustrating at first, but it revealed **why** modern C++ evolved the way it did. Understanding the pain points of C++98 makes modern features feel like solutions, not magic.

### 2. Diamond Inheritance & vtable
Without `virtual` inheritance, a class inheriting from two classes that share a common base gets **two copies** of the base — causing ambiguity. Understanding how the vtable resolves virtual function calls was key to grasping polymorphism at a deeper level.

### 3. Deep Copy in OCF
When a class has pointer members, the default copy constructor and assignment operator perform a **shallow copy** (copying the pointer, not the data). This leads to double free on destruction. Implementing proper deep copy in every OCF class became second nature.

### 4. Exception Safety
Designing classes that behave correctly when exceptions are thrown — especially during construction and assignment — requires thinking about resource ownership and cleanup paths that I hadn't considered coming from C.

---

## License

This project was developed as part of the 42 curriculum at Hive Helsinki.
