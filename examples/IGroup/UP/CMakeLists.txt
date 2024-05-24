set(EXE_NAME
        UParticle)

set(SOURCE
        UParticle.cpp)

add_executable(${EXE_NAME}
        ${SOURCE})

target_link_libraries(${EXE_NAME}
        PRIVATE
        Driver)
