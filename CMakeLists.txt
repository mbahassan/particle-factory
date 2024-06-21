cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

# Set the CMP0104 policy
cmake_policy(SET CMP0104 NEW)

project(ParticleFactory LANGUAGES CXX CUDA)

# Whether to compile it with cuda or not
option(USE_CUDA "Use Cuda" ON)
message(STATUS "USE_CUDA: ${USE_CUDA}")
if(USE_CUDA)
    add_definitions(-DUSE_CUDA)
endif()


set(CMAKE_CXX_STANDARD 26)

add_subdirectory(src)
add_subdirectory(examples)

