project (GTK_Touch_Test)

cmake_minimum_required(VERSION 2.6)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GTK2 REQUIRED gtk+-2.0)
include_directories(${GTK2_INCLUDE_DIRS})
link_directories(${GTK2_LIBRARY_DIRS})
add_definitions(${GTK2_CLFAGS_OTHER})

add_executable(GTK_Touch_Test main.c)
target_link_libraries(GTK_Touch_Test ${GTK2_LIBRARIES})
