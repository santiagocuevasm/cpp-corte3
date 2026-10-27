cmake_minimum_required(VERSION 3.14)
project(cpp_corte3 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ejercicios de Exercism
add_executable(clock_app clock/main.cpp clock/clock.cpp)
add_executable(meetup_app meetup/main.cpp meetup/meetup.cpp)

# Ejercicios de LeetCode: toma todos los .cpp de cada carpeta
file(GLOB EJ1_SRC ejercicio1_underground_system/*.cpp)
file(GLOB EJ2_SRC ejercicio2_atm_machine/*.cpp)
file(GLOB EJ3_SRC ejercicio3_auction_system/*.cpp)
add_executable(underground_system ${EJ1_SRC})
add_executable(atm_machine ${EJ2_SRC})
add_executable(auction_system ${EJ3_SRC})
