#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <cstdint>
#include <string>

static const uint32_t WINDOW_DEFAULT_WIDTH  = 800;
static const uint32_t WINDOW_DEFAULT_HEIGHT = 600;
static const char* WINDOW_DEFAULT_TITLE = "Default";

class Window {
public:
    Window(uint32_t width = WINDOW_DEFAULT_WIDTH, 
           uint32_t height = WINDOW_DEFAULT_HEIGHT, 
           const char* title = WINDOW_DEFAULT_TITLE);
    ~Window();

    void set_should_close(bool should_close);

    bool should_close() const;

    GLFWwindow* get_window() const;

private:
    GLFWwindow* m_window = nullptr;
    uint32_t m_width  = WINDOW_DEFAULT_WIDTH;
    uint32_t m_height = WINDOW_DEFAULT_HEIGHT;
    std::string m_title = nullptr;
};
