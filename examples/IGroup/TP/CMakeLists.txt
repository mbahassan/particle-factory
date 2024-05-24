set(EXE_NAME TParticle)

set(SOURCE TParticle.cpp)

#set(CMAKE_CXX_STANDARD 17)

add_executable(${EXE_NAME}  ${SOURCE})

target_link_libraries(${EXE_NAME}
        PRIVATE
        Driver)
