cmake_minimum_required( VERSION 3.11.0)

set(CMAKE_VERBOSE_MAKEFILE ON)

project(eigen_matrix_bar)

set(EIGEN_DIR "other_libs/eigen-3.4.0")
include_directories(${EIGEN_DIR})

# source files
set(SOURCE_DIR "src/example")

add_subdirectory(pybind11) # add pybind11
pybind11_add_module(eigen_matrix_bar ${SOURCES} "${SOURCE_DIR}/eigen_matrix.cpp")