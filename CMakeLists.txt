cmake_minimum_required(VERSION 3.10)
project(Twease)

set(CMAKE_CXX_STANDARD 17)


file(GLOB_RECURSE SRC
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

add_executable(Twease ${SRC})

# Include directories
target_include_directories(Twease PRIVATE 
    ${CMAKE_SOURCE_DIR}/include
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Twease)

# Remove ALL_BUILD and ZERO_CHECK targets
set(CMAKE_SUPPRESS_REGENERATION true)
