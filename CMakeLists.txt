cmake_minimum_required(VERSION 3.17)
project(One)

set(CMAKE_CXX_STANDARD 20)
find_package(PkgConfig REQUIRED)

file(GLOB_RECURSE SRCS src/*.cpp)

include_directories(include)

add_executable(One ${SRCS} src/Graphics/GL3/Buffers/GL3IndexBuffer.cpp include/Graphics/GL3/Buffers/GL3IndexBuffer.h include/Graphics/GL3/GL3.h src/Graphics/Commands.cpp include/Graphics/Commands.h src/Graphics/GL3/GL3Commands.cpp include/Graphics/GL3/GL3Commands.h src/Graphics/GL3/Buffers/GL3VertexBufferArray.cpp include/Graphics/GL3/Buffers/GL3VertexBufferArray.h include/Graphics/Features.h)

pkg_search_module(GLFW REQUIRED glfw3)
find_package(GLEW REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS} $(GLEW_INCLUDE_DIRS))
target_link_libraries(One ${GLFW_LIBRARIES} ${GLEW_LIBRARIES} OpenGL)
