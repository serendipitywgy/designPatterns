cmake_minimum_required(VERSION 3.20)
project(DesignPatterns)

set(CMAKE_CXX_STANDARD 17)

#设置可执行文件输出路径

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(creational)
#add_subdirectory(structural)
#add_subdirectory(behavioral)
