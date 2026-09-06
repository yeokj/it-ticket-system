# IT Ticket Management System

An optimized, object-oriented IT incident tracking and management system implemented in modern C++ (C++17). Designed with a focus on defensive programming, clean domain separation, smart pointer lifecycle management, and resilient flat-file persistence.

---

## Architecture Overview

The system transitions traditional monolithic procedural logic into an enterprise-grade service-oriented architecture:

* **Domain Modeling & Polymorphism (`include/models/`):** Utilizes an extensible inheritance hierarchy (`User` → `Client`, `Technician`) with virtual destructors and polymorphic ownership. Tickets encapsulate entities via `std::shared_ptr<Client>` and `std::shared_ptr<Technician>` rather than raw strings.
* **Creational Patterns (`include/factories/`):** Implements a dedicated `UserFactory` to decouple raw record tokenization and instantiation from the persistence layer.
* **Persistence Engine (`include/storage/`):** Custom flat-file serialization engine (`StorageManager`) managing relational mapping across `client.csv`, `technician.csv`, and `ticket.csv`. Reconstructs in-memory object graphs via foreign-key map lookups during startup hydration.
* **Role-Based Access Control (RBAC):** Granular permission enforcement across `Client`, `Technician`, and `Admin` tiers, guarding administrative routines and isolating private client views.
* **Domain Exception Handling (`include/utils/`):** Custom domain exceptions (`DatabaseCorruptedException`, `UnauthorizedAccessException`) wrapping critical parsing and execution paths.

---

## Project Structure

```text
├── CMakeLists.txt
├── README.md
├── include/
│   ├── factories/
│   │   └── UserFactory.h
│   ├── models/
│   │   ├── Ticket.h
│   │   └── User.h
│   ├── services/
│   │   └── TicketService.h
│   ├── storage/
│   │   └── StorageManager.h
│   └── utils/
│       ├── Exceptions.h
│       └── TicketHelper.h
└── src/
    ├── factories/
    │   └── UserFactory.cpp
    ├── models/
    │   ├── Ticket.cpp
    │   └── User.cpp
    ├── services/
    │   └── TicketService.cpp
    ├── storage/
    │   └── StorageManager.cpp
    ├── utils/
    │   ├── Exceptions.cpp
    │   └── TicketHelper.cpp
    └── main.cpp
```

---

## Key Features

* **Auto-Priority & Date Engine:** Algorithmic calculation of incident priority thresholds based on temporal delta calculations between system timestamps and target due dates.
* **State Synchronization & Deduplication:** O(1) runtime validation sets guarding against primary key collisions, paired with email lookup registries to avoid entity duplication.
* **Multi-View Query Pipelines:** Overloaded display and search routines supporting global organizational sorting (Priority, Due Date) and sandboxed client views.
* **Defensive Input Handling:** Stream sanitization and validation firewalls preventing trailing newline bugs and parsing overflows.

---

## Build & Installation

### Prerequisites
* **C++ Compiler:** Modern compiler supporting C++17 (Clang, GCC, or MSVC)
* **Build System:** CMake (Version 3.10 or higher)

### Build Instructions

1. Clone the repository:
   ```bash
   git clone https://github.com/yeokj/it-ticket-system.git
   cd it-ticket-system
   ```

2. Generate the build files:
   ```bash
   cmake -B build
   ```

3. Compile the executable:
   ```bash
   cmake --build build
   ```

4. Run the application:
   ```bash
   ./build/ticket_system
   ```
   *(On Windows platforms: `.\build\Debug\ticket_system.exe`)*

---

## Data Schema

The persistence layer relies on three synchronized CSV files managed automatically at application shutdown:

* `client.csv`: `ID, Name, Email, Password, Company`
* `technician.csv`: `ID, Name, Email, Password, EmployeeID, Department`
* `ticket.csv`: `TicketID, ClientID, TechID, IssueDescription, DueDate, PriorityLevel, IssueStatus`