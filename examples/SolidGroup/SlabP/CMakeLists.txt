set(EXE_NAME Slab)

set(SOURCE Slab.cpp)


add_executable(${EXE_NAME}  ${SOURCE})

target_link_libraries(${EXE_NAME}
        PRIVATE
        Driver)

include_directories( ${CMAKE_SOURCE_DIR}/src)
include_directories( ${CMAKE_SOURCE_DIR}/examples/SolidGroup/SlabP)
