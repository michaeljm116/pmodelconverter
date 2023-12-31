cmake_minimum_required(VERSION 3.14)
project(PModelConverter)

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Winvalid-pch")

# Different settings for Debug and Release
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  message("Building in Debug mode")
  add_definitions(-DDEBUG_MODE)
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
  message("Building in Release mode")
endif()


# Include the submodules' header files
include_directories(
    include
)
include_directories(
    lib/imgui
    lib/imgui/backends
    lib/imgui/examples/libs/glfw/include
)

# Add source files and header files
file(GLOB SYSTEMS_SOURCE
    src/*.cpp
    lib/imgui/*.cpp
    lib/imgui/backends/*.cpp
)
file(GLOB SYSTEMS_HEADERS
    include/*.h
    include/*.hpp
    lib/imgui/*.h
    lib/imgui/backends/*.h
)

# Create the library
add_library(PModelConverterLib STATIC ${SYSTEMS_SOURCE} ${SYSTEMS_HEADERS})
#target_link_libraries(PModelConverterLib Vulkan::Headers)

target_link_libraries(PModelConverterLib "../lib/glfw3")

# Link the include libs
target_include_directories(PModelConverterLib PRIVATE lib/imgui)

find_package(Vulkan REQUIRED)
target_link_libraries(PModelConverterLib Vulkan::Vulkan)

# Define DEBUG_MODE for debug configuration
target_compile_definitions(PModelConverterLib PRIVATE $<$<CONFIG:Debug>:DEBUG_MODE>)

# Create the executable
add_executable(PModelConverter src/main.cpp)
target_precompile_headers(PModelConverter PRIVATE include/pch.h)
target_link_libraries(PModelConverter PModelConverterLib)
