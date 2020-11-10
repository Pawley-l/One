cmake_minimum_required(VERSION 3.17)
project(One)

set(CMAKE_CXX_STANDARD 20)
find_package(PkgConfig REQUIRED)

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE PROTECT_ONE_SRC games/ProjectOne/*.cpp)
file(GLOB_RECURSE TESTS tests/Units/*.h)

include_directories(include)
include_directories(lib)

add_executable(OneTest tests/main.cpp ${SRCS})
add_library(One ${SRCS})
add_executable(ProjectOne games/main.cpp ${PROTECT_ONE_SRC} ${SRCS})
add_executable(UnitTests tests/tests_main.cpp ${TESTS} ${SRCS})

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
include_directories(lib/googletest/googlemock/include)
link_directories(lib/googletest)

pkg_search_module(GLFW REQUIRED glfw3)
find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

include_directories(${GLFW_INCLUDE_DIRS} $(GLEW_INCLUDE_DIRS) $(GLM_INCLUDE_DIRS))
target_link_libraries(OneTest ${GLFW_LIBRARIES} ${GLEW_LIBRARIES} ${GLM_LIBRARIES} OpenGL)
target_link_libraries(ProjectOne ${GLFW_LIBRARIES} ${GLEW_LIBRARIES} ${GLM_LIBRARIES} OpenGL)
target_link_libraries(One ${GLFW_LIBRARIES} ${GLEW_LIBRARIES} ${GLM_LIBRARIES} OpenGL)
target_link_libraries(UnitTests ${GLFW_LIBRARIES} ${GLEW_LIBRARIES} ${GLM_LIBRARIES} gtest gtest_main OpenGL)

find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doxygen-config)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/doxygen-config.doxygen)

    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    add_custom_target( doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)