cmake_minimum_required(VERSION 3.17)
project(One)

set(CMAKE_CXX_STANDARD 20)
find_package(PkgConfig REQUIRED)

file(GLOB_RECURSE SRCS src/*.cpp)

include_directories(include)
include_directories(lib)

add_executable(One ${SRCS} include/Common.h src/Renderer/Camera.cpp include/Renderer/Camera.h src/Renderer/BaseRenderer.cpp)

pkg_search_module(GLFW REQUIRED glfw3)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS} $(GLEW_INCLUDE_DIRS) $(GLM_INCLUDE_DIRS))
target_link_libraries(One ${GLFW_LIBRARIES} ${GLEW_LIBRARIES} ${GLM_LIBRARIES} OpenGL)

find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doxygen-config)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/doxygen-config.doxygen)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)