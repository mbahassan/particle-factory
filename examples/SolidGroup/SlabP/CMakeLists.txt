set(EXE_NAME Slab)

set(SOURCE Slab.cpp)


add_executable(${EXE_NAME}  ${SOURCE})

target_link_libraries(${EXE_NAME}
        PRIVATE
        BondedPG)
