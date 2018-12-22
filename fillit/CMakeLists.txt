cmake_minimum_required(VERSION 3.13)
project(fillit_input)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(MAIN_PROJECT_SRC_LIST main)
add_executable(main ${MAIN_PROJECT_SRC_LIST})
add_subdirectory(libft)
target_link_libraries(main libft)
