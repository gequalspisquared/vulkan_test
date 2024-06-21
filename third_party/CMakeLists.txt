set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw)
# add_subdirectory(lib/glm)
# add_subdirectory(lib/imgui)
add_subdirectory(fmt EXCLUDE_FROM_ALL)
add_subdirectory(tinyobjloader EXCLUDE_FROM_ALL)

add_library(glm INTERFACE)
add_library(stb INTERFACE)

target_include_directories(glm INTERFACE glm)
target_include_directories(stb INTERFACE stb)

add_library(imgui STATIC)

target_include_directories(imgui PUBLIC imgui)

target_sources(imgui PRIVATE 
    imgui/imgui.h
    imgui/imgui.cpp

    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui_tables.cpp
    imgui/backends/imgui_impl_vulkan.cpp
    imgui/backends/imgui_impl_glfw.cpp
)
