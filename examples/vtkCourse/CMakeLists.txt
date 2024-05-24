set(EXE_NAME vtkRun)

set(SOURCE vtkRun.cpp)

add_executable(${EXE_NAME} ${SOURCE})

target_link_libraries(${EXE_NAME}
        PRIVATE
        Driver)
