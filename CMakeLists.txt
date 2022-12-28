# CMakeList.txt : CMake project for Dullahan-Game-Engine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Dullahan-Game-Engine")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)



# Add source to this project's executable.
add_executable (Dullahan-Game-Engine "Dullahan-Game-Engine.cpp" "Dullahan-Game-Engine.h")

add_subdirectory(Dependencias/glfw-3.3.8)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Dullahan-Game-Engine PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(Dullahan-Game-Engine glfw)
#target_link_libraries(Dullahan-Game-Engine OpenGL::GL)
# TODO: Add tests and install targets if needed.
