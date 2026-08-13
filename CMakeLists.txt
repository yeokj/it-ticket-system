cmake_minimum_required(VERSION 3.10)

project(ITTicketSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/models/Ticket.cpp
    src/models/User.cpp
    src/services/TicketService.cpp
    src/storage/StorageManager.cpp
    src/utils/TicketHelper.cpp
    src/factories/UserFactory.cpp
)

add_executable(ticket_system ${SOURCES})

target_include_directories(ticket_system PRIVATE 
    include
    include/models
    include/services
    include/utils
    include/storage
    include/factories
)