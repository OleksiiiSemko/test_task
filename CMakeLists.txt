cmake_minimum_required(VERSION 3.17)
project(pangea)


find_package( OpenGL REQUIRED )

include_directories( ${OPENGL_INCLUDE_DIRS} )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(3rdparty/curlpp)
add_subdirectory(3rdparty/glfw)
add_subdirectory(3rdparty/glad)

set(CMAKE_CXX_STANDARD 11)

add_executable(${CMAKE_PROJECT_NAME}
        main.cpp
        Window.cpp
        Shader.cpp
        Layout.cpp
        Texture.cpp
        )

target_link_libraries(pangea curlpp)
target_link_libraries(pangea glfw)
target_link_libraries(pangea glad)
target_link_libraries(pangea OpenGL::GL)
target_link_libraries(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE_DIR}/3rdparty/soil/build/lib/libSOIL.a)
link_libraries()

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
        "${PROJECT_SOURCE_DIR}/3rdparty/curlpp/include")
target_include_directories(pangea PUBLIC
        "${PROJECT_SOURCE_DIR}/3rdparty/soil/build/include")




