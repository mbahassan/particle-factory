cmake_minimum_required(VERSION 3.24)

#project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(spherePack SphereParticle.cpp)
target_link_libraries(spherePack PRIVATE BondedPG)
