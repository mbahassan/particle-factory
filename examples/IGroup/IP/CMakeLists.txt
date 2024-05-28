set(EXE_NAME IParticle)

set(SOURCE IParticle.cpp)

add_executable(${EXE_NAME} ${SOURCE})

target_link_libraries(${EXE_NAME}
        PRIVATE
        Driver)

include_directories( ${CMAKE_SOURCE_DIR}/src)