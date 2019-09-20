cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME "homework")

project(${PROJECT_NAME} VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -Wextra -Wshadow -Wundef -Wno-missing-field-initializers")

#set(LIB_IMPLEMENTATION "composition")
set(LIB_IMPLEMENTATION "inheritance")
set(PATH_TO_LIB_SRC "./libwinesrc/${LIB_IMPLEMENTATION}")

include_directories(./${PATH_TO_LIB_SRC}/inc)

add_library (
	wine SHARED
	${PATH_TO_LIB_SRC}/src/Wine.cpp
)

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/wine_example.cpp
)

target_link_libraries(${PROJECT_NAME} wine)


