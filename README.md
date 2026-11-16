# Object-Oriented Programming in C++ Lab (ECE121)

**Department of Electronics Engineering (VLSI Design & Technology)**  
**Nitte Meenakshi Institute of Technology (NMIT)**  

* **Student Name:** Amruth RM  
* **Student ID / USN:** nb25vdt006  
* **Email:** nb25vdt006.amruth@nmit.ac.in  
* **Language & Standard:** C++17  
* **Compiler:** GNU C++ Compiler (GCC / g++ 13+ / 16+)  

---

## 📌 Repository Overview

This repository contains the complete coursework and lab implementations for **Object-Oriented Programming using C++ (ECE121)**. It includes:
1. **Lab Tasks 1 & 2**: Major milestone assessment projects synthesizing core and advanced OOP principles.
2. **Weekly DIY (Do-It-Yourself) Programs**: All 39 challenge problems across Weeks 1 to 13 from the official lab manual.
3. **Weekly Demonstration Programs**: In-lab walkthrough programs illustrating essential C++ mechanisms.

---

## 📂 Repository Structure

```
.
├── task1.cpp                        # Lab Task 1 (Root Access)
├── task2.cpp                        # Lab Task 2 (Root Access)
│
├── Tasks/
│   ├── Task1/
│   │   └── task1.cpp                # Task 1: Student Management System (Weeks 1-6)
│   └── Task2/
│       └── task2.cpp                # Task 2: Student Result Management System (Weeks 7-13)
│
├── DIY/                             # Complete 39 Do-It-Yourself Lab Programs
│   ├── Week01/                      # Basic I/O, Strings, Character Manipulation
│   │   ├── diy1_1.cpp               # 1.1 Vowel & Consonant Counter
│   │   ├── diy1_2.cpp               # 1.2 Anagram Test
│   │   └── diy1_3.cpp               # 1.3 Reverse Word Order
│   ├── Week02/                      # Functions, Overloading, Defaults, Inline
│   │   ├── diy2_1.cpp               # 2.1 Overloaded Volume (Cube, Cuboid, Cylinder)
│   │   ├── diy2_2.cpp               # 2.2 Default-Argument Calculator (power)
│   │   └── diy2_3.cpp               # 2.3 Inline Overloaded minVal
│   ├── Week03/                      # Classes, Objects & Encapsulation
│   │   ├── diy3_1.cpp               # 3.1 Rectangle Class with Validation & Method Chaining
│   │   ├── diy3_2.cpp               # 3.2 Counter Array Exercise
│   │   └── diy3_3.cpp               # 3.3 Complex Number Class
│   ├── Week04/                      # Constructors, Destructors & Dynamic Memory
│   │   ├── diy4_1.cpp               # 4.1 Dynamic Matrix with Deep Copy & Destructor
│   │   ├── diy4_2.cpp               # 4.2 Dynamic Stack with Destructor
│   │   └── diy4_3.cpp               # 4.3 Lifetime Logger (Dynamic Allocation & Destruction)
│   ├── Week05/                      # Static Members & Friend Functions
│   │   ├── diy5_1.cpp               # 5.1 Object Counter (totalCreated & currentlyAlive)
│   │   ├── diy5_2.cpp               # 5.2 Friend Function laterOf(Time, Time)
│   │   └── diy5_3.cpp               # 5.3 Unique ID Factory (Auto-incrementing Order IDs)
│   ├── Week06/                      # Operator Overloading
│   │   ├── diy6_1.cpp               # 6.1 Money Arithmetic (+ and - with Paise Carry/Borrow)
│   │   ├── diy6_2.cpp               # 6.2 Fraction Stream I/O (<<, >>) & Auto-Simplification
│   │   └── diy6_3.cpp               # 6.3 Safe Array with Bounds-Checked operator[]
│   ├── Week07/                      # Inheritance & Diamond Resolution
│   │   ├── diy7_1.cpp               # 7.1 Employee Hierarchy (Manager & Engineer)
│   │   ├── diy7_2.cpp               # 7.2 Multilevel Inheritance Constructor/Destructor Order
│   │   └── diy7_3.cpp               # 7.3 Resolving Diamond Problem via Virtual Base Class
│   ├── Week08/                      # Polymorphism & Virtual Functions
│   │   ├── diy8_1.cpp               # 8.1 Abstract Account Interface (Savings & Current)
│   │   ├── diy8_2.cpp               # 8.2 Polymorphic Logger (ConsoleLogger & FileLogger)
│   │   └── diy8_3.cpp               # 8.3 Virtual Destructor Proof of Cleanup
│   ├── Week09/                      # Exception Handling
│   │   ├── diy9_1.cpp               # 9.1 Safe Withdrawal with InsufficientFundsException
│   │   ├── diy9_2.cpp               # 9.2 Stack Overflow and Underflow Custom Exceptions
│   │   └── diy9_3.cpp               # 9.3 Exception Handler Catch Ordering Demo
│   ├── Week10/                      # File Input / Output
│   │   ├── diy10_1.cpp              # 10.1 Numerical Statistics from File (count, sum, min, max)
│   │   ├── diy10_2.cpp              # 10.2 Line-Numbered File Copying
│   │   └── diy10_3.cpp              # 10.3 Object Deserialization & Topper Finder
│   ├── Week11/                      # Templates & STL Containers
│   │   ├── diy11_1.cpp              # 11.1 Generic Utility Templates (swapVals & findMax)
│   │   ├── diy11_2.cpp              # 11.2 Generic Queue<T> Class Template
│   │   └── diy11_3.cpp              # 11.3 Word Frequency Counter via std::unordered_map
│   ├── Week12/                      # STL Algorithms & Lambdas
│   │   ├── diy12_1.cpp              # 12.1 Sorting Pairs by Value using Lambdas
│   │   ├── diy12_2.cpp              # 12.2 Top-3 Largest Values via std::priority_queue (Heap)
│   │   └── diy12_3.cpp              # 12.3 Custom Aggregates via std::accumulate & Lambdas
│   └── Week13/                      # Modern C++, Smart Pointers & Multithreading
│       ├── diy13_1.cpp              # 13.1 RAII with std::unique_ptr (No Raw Deletes)
│       ├── diy13_2.cpp              # 13.2 Polymorphic Shape Factory v2 with std::unique_ptr
│       └── diy13_3.cpp              # 13.3 Race Condition Elimination with std::mutex
│
└── program*.cpp                     # Laboratory Walkthrough / In-Lab Exercise Programs
```

---

## 📋 Lab Tasks Summary

### Task 1: Student Management System (Weeks 1–6)
* **File:** `task1.cpp` / `Tasks/Task1/task1.cpp`
* **Objective:** Design and implement a `Student` class showcasing encapsulation, parameterized constructors with member initializer lists, destructor count tracking, dynamic object allocation with `new`/`delete`, static data members and methods, function overloading (`display`), friend functions (`showDetails`), and operator overloading (`operator>`).
* **Key Features:**
  * Validating setters ensuring marks reside in $[0, 100]$.
  * Accurate real-time tracking of active instances through static counters.
  * Natural comparison between objects using the overloaded `>` operator.

### Task 2: Student Result Management System (Weeks 7–13)
* **File:** `task2.cpp` / `Tasks/Task2/task2.cpp`
* **Objective:** Develop a robust Student Result Management System featuring inheritance (`Student` base class $\to$ `Result` derived class), runtime polymorphism with virtual functions and virtual destructors, template range validation, custom exception handling (`InvalidMarksException`), persistent file storage (`records.txt`), and STL algorithms with modern lambda expressions.
* **Key Features:**
  * Strict validation rejecting out-of-range marks mid-construction.
  * Polymorphic display of student attributes and subject marks.
  * Persistence to and retrieval from disk using formatted stream I/O.
  * High-performance querying: filtering scores with `std::copy_if`, tallying pass/fail with `std::count_if`, and descending ranking with `std::sort`.

---

## 🛠 Compilation and Execution

All programs are written in clean, standard C++17 with zero third-party dependencies.

### Compiling Tasks
```bash
# Task 1
g++ -std=c++17 -Wall -Wextra task1.cpp -o task1.exe
./task1.exe

# Task 2
g++ -std=c++17 -Wall -Wextra task2.cpp -o task2.exe
./task2.exe
```

### Compiling Any DIY Program
```bash
# Example: Week 6 DIY 1 (Money Arithmetic)
g++ -std=c++17 -Wall -Wextra DIY/Week06/diy6_1.cpp -o diy6_1.exe
./diy6_1.exe

# Example: Week 13 DIY 3 (Multithreading & Mutex)
g++ -std=c++17 -Wall -Wextra -pthread DIY/Week13/diy13_3.cpp -o diy13_3.exe
./diy13_3.exe
```

---

## 📜 Academic Integrity & Declaration
All programs, solutions, and implementations in this repository represent my original laboratory work completed for Semester III Object-Oriented Programming using C++ Lab (ECE121).
