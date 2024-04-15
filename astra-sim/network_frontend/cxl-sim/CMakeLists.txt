# CMake Requirement
cmake_minimum_required(VERSION 3.15)

# C++ requirement
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the build type to Release if not specified
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

# Setup project
project(AstraSim_CXLSim)

# Compilation target
set(BUILDTARGET "all" CACHE STRING "Compilation target ([all]/Analytical/Sophisticated)")

# Include src files to compile
file(GLOB srcs
        ${CMAKE_CURRENT_SOURCE_DIR}/common/*.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/congestion_unaware/*.cc
)

if (BUILDTARGET STREQUAL "all" OR BUILDTARGET STREQUAL "Analytical")
    add_executable(AstraSim_CXLSim_Congestion_Unaware ${srcs})
    target_sources(AstraSim_CXLSim_Congestion_Unaware PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/congestion_unaware/main.cc)

    # Link libraries
    target_link_libraries(AstraSim_CXLSim_Congestion_Unaware LINK_PRIVATE AstraSim)
    target_link_libraries(AstraSim_CXLSim_Congestion_Unaware LINK_PRIVATE CXLNetworkSim)

    # Include directories
    target_include_directories(AstraSim_CXLSim_Congestion_Unaware PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/)
    target_include_directories(AstraSim_CXLSim_Congestion_Unaware PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../extern/)
    target_include_directories(AstraSim_CXLSim_Congestion_Unaware PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../../extern/helper)

    # Properties
    set_target_properties(AstraSim_CXLSim_Congestion_Unaware PROPERTIES COMPILE_WARNING_AS_ERROR ON)
    set_target_properties(AstraSim_CXLSim_Congestion_Unaware
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../bin/
            LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib/
            ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../lib/
    )
endif ()
