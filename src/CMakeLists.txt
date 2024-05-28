set(LIB_NAME Driver)
set(SOURCES
        RenderShape.cpp
        Shape.cpp
        File.cpp
        Sphere.cpp
        Plate.cpp
        Point.cpp
        CircleSection.cpp
        )

add_library(${LIB_NAME} ${SOURCES})

include_directories( ${CMAKE_SOURCE_DIR}/src )

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
