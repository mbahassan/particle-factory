
# VTK Library
set(VTK_DIR "${CMAKE_SOURCE_DIR}/../3rdParty/VTK-build")
find_package(VTK COMPONENTS
        CommonColor
        CommonCore
        CommonDataModel
        FiltersSources
        InteractionStyle
        RenderingContextOpenGL2
        RenderingCore
        RenderingFreeType
        RenderingGL2PSOpenGL2
        RenderingOpenGL2
)

if (NOT VTK_FOUND)
    message(FATAL_ERROR "Generator: Unable to find the VTK build folder.")
endif()

# Cmake part
set(LIB_NAME Driver)
set(CPU_SOURCES
        RenderShape.cpp
        Shape.cpp
        File.cpp
        Sphere.cpp
        Plate.cpp
        Point.cpp
        CircleSection.cpp
)

#add_library(${LIB_NAME} ${CPU_SOURCES})

if( ("${CMAKE_VERSION}" VERSION_EQUAL 3.8) OR ("${CMAKE_VERSION}" VERSION_GREATER 3.8) )
    if(USE_CUDA)
        enable_language("CUDA")
        add_library(${LIB_NAME} ${CPU_SOURCES} ${GPU_SOURCES})
    else(USE_CUDA)
        add_library(${LIB_NAME} ${CPU_SOURCES})
    endif()
endif()


include_directories( ${CMAKE_SOURCE_DIR}/src )

target_include_directories(
        ${LIB_NAME}
        PUBLIC
        ${CMAKE_SOURCE_DIR}/Kernel
        )

target_link_libraries(${LIB_NAME}
        PUBLIC
        ${VTK_LIBRARIES})

vtk_module_autoinit(
        TARGETS ${LIB_NAME}
        MODULES ${VTK_LIBRARIES}
)
