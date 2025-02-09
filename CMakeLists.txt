cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(viewimage VERSION 3.0)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

set(SFML_INCLUDE_DIR "D:/dev/library/SFML-2.6.2/include")
set(SFML_DIR "D:/dev/library/SFML-2.6.2/lib/cmake/SFML")

set(CMAKE_BUILD_TYPE Debug)

find_package(SFML COMPONENTS network audio graphics window system REQUIRED)

add_executable(viewimage ${SRC_FILES})

target_link_libraries(viewimage sfml-network sfml-audio sfml-graphics sfml-window sfml-system)
#target_link_libraries(viewimage PUBLIC ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})