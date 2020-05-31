cmake_minimum_required(VERSION 3.16)
project(TP2_Operativos C)

set(CMAKE_C_STANDARD 11)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})
add_executable(TP2_Operativos main.c .idea/Calendarizer.c .idea/Cola.c .idea/Process.c .idea/Calendarizer.h .idea/Cola.h .idea/Process.h)

target_link_libraries(TP2_Operativos ${GTK3_LIBRARIES})