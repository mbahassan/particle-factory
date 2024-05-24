set(EXE_NAME IParticle)

set(SOURCE IParticle.cpp)

add_executable(${EXE_NAME} ${SOURCE})

target_link_libraries(${EXE_NAME}
        PRIVATE
        Driver)
