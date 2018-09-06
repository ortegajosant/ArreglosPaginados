cmake_minimum_required(VERSION 3.12)
project(PagedArray)

set(CMAKE_CXX_STANDARD 14)

add_executable(PagedArray src/pagedarray/PagedArray.cpp src/pagedarray/PagedArray.h main.cpp src/Page/Page.cpp src/Page/Page.h)