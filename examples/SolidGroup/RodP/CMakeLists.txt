cmake_minimum_required(VERSION 3.24)

set(CMAKE_CXX_STANDARD 17)

add_executable(RodParticle RodParticle.cpp)
target_link_libraries(RodParticle PRIVATE Driver)


include_directories( ${CMAKE_SOURCE_DIR}/examples/SolidGroup/RodP)

include_directories( ${CMAKE_SOURCE_DIR}/src)
