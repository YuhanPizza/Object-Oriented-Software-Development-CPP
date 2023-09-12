# Object Oriented Software Development Using C++ Workshop README

Welcome to the "Object Oriented Software Development Using C++" Workshop series! This repository serves as a comprehensive collection of workshops completed during my course in OOP345. Each workshop showcases my knowledge and problem-solving skills on various C++ topics. Additionally, you'll find my reflections on each topic, providing insights into how I understood and tackled these challenges.

## Workshop Topics

### 1: Across Translation Units
- Explore the fundamentals of C++ and the Object-Oriented paradigm.
- Learn key terminology, understand namespaces, and get familiar with compilation and platforms.
- Delve into pre-processing directives and macros.

### 2: Containers
- Dive into the various types in C++, from fundamental to compound types.
- Work with classes, understand class relationships, and explore templates.
- Discover the concepts of composition, aggregation, and association.

### 3: Functions and Error Handling
- Learn about C++ expressions, operators, and functions.
- Simplify syntax, understand linkage, and explore recursive functions.
- Dive into pointers to functions, function objects, lambda expressions, and error handling with exceptions.

### 4: Move and Copy Semantics
- Explore the C++ memory model, raw pointers, C-style character strings, and smart pointers.
- Understand exclusive ownership with unique_ptr and shared ownership with shared_ptr.

### 5: Multi-Threading
- Get an introduction to multi-threading, processes, threads, and the future library.
- Explore thread local storage duration.

### 6: STL Algorithms
- Get hands-on with linked lists and the Standard Template Library (STL).
- Explore sequential containers, adapters, iterators, and algorithm libraries.

### 7: STL Containers
- Understand file stream objects, class hierarchy, file objects, binary access, and string classes.
- Navigate platform-dependent input/output.
- Compare C++11, C11 syntax, C++14, and C++17.

### 8: Smart Pointers
- Delve into exclusive ownership with unique_ptr and shared ownership with shared_ptr.

### 9: Templates
- Explore template syntax, specialization, ambiguities, and static members in class templates.

### Assembly Line Simulation Project
- This section provides an in-depth overview of the Assembly Line Simulation Project, which serves as the capstone of our Object-Oriented Programming (OOP) course (OOP345). This project challenges us to create a sophisticated simulation of an assembly line equipped with multiple stations to efficiently manage and fulfill customer orders.

#### Project Objectives
The primary objectives of the Assembly Line Simulation Project are as follows:
- **Realistic Simulation**: The project aims to create a realistic representation of an assembly line environment, where various stations work together to process customer orders.
- **Object-Oriented Design**: We apply advanced object-oriented design principles to ensure the project's modularity and extensibility. Each station, customer order, and the line manager is meticulously designed as an object with a well-defined role in the simulation.
- **File Input and Parsing**: Extensive file input and parsing are integral to configuring the assembly line. We read data from files to initialize and fine-tune the assembly line components, showcasing our expertise in file handling.
- **Smart Pointers and Resource Management**: Smart pointers, including `unique_ptr` and `shared_ptr`, play a pivotal role in managing memory efficiently and ensuring proper resource cleanup throughout the project.
- **Exception Handling**: We implement robust exception handling mechanisms to gracefully manage errors and exceptional scenarios, demonstrating our commitment to the reliability of the simulation.
- **Data Structures and Algorithms**: The simulation relies on well-designed data structures such as queues and vectors to handle the flow of customer orders and maintain the state of stations on the assembly line.
- **Modularization**: The project is thoughtfully divided into separate modules (e.g., `Utilities`, `Station`, `CustomerOrder`, `Workstation`, and `LineManager`) to promote code reusability and maintainability.
- **Object Interactions**: Objects within the assembly line interact seamlessly to fulfill customer orders efficiently. The line manager orchestrates the movement of orders through stations, and stations process orders based on available inventory.
- **Advanced C++ Features**: We leverage advanced C++ features, including templates, custom constructors, move semantics, and dynamic memory allocation, to implement a highly flexible and efficient simulation.

#### Project Structure
The project is organized into several modules, each responsible for a specific aspect of the assembly line simulation. These modules include:
- `Utilities`: Provides utility functions and classes used throughout the project.
- `Station`: Represents various types of stations on the assembly line.
- `CustomerOrder`: Encapsulates customer orders and their processing.
- `Workstation`: Defines workstations that perform tasks on customer orders.
- `LineManager`: Manages the flow of customer orders through the assembly line.


## Getting Started

To explore each workshop's content, navigate to the corresponding workshop directory in this repository. Inside each directory, you will find my solutions, code examples, explanations, and reflections on the respective topic. Feel free to use these materials as a learning resource or reference.
