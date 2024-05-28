cmake_minimum_required(VERSION 3.24)

set(EXE_NAME Disk)
set(SOURCES Disk.cpp)


add_executable(${EXE_NAME} ${SOURCES})
target_link_libraries(${EXE_NAME}
        PRIVATE Driver)

include_directories( ${CMAKE_SOURCE_DIR}/src)