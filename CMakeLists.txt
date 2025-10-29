cmake_minimum_required(VERSION 3.14)

project(CP1-THREADS- LANGUAGES C)

# Create separate executables for each C file
add_executable(t1 mt-example-0.c)
add_executable(t2 mt-example.c)
add_executable(t3 order_violation.c)
add_executable(t4 order_violation_solution.c)
add_executable(t5 thread.c)

