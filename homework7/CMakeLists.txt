cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME "homework")

project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -Wextra -Wshadow -Wundef -Wno-missing-field-initializers")

include_directories(./inc)

add_library (
	simplayer SHARED
	${CMAKE_CURRENT_SOURCE_DIR}/src/Parser.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Player.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Decoder/AudioDecoder.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Decoder/VideoDecoder.cpp
)

add_executable(${PROJECT_NAME}
   ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_link_libraries(${PROJECT_NAME} simplayer)
