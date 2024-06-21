#include "Window.hpp"
#include "GLFW/glfw3.h"

#include <iostream>

Window::Window(uint32_t width, uint32_t height, const char* title) 
    : m_width(width), m_height(height), m_title(title) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!\n";
        return;
    }

    if (!glfwVulkanSupported()) {
        std::cerr << "GLFW Vulkan is not supported!\n";
        return;
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);

    if (m_window == nullptr) {
        std::cerr << "Failed to create Window!\n";
    }
}

Window::~Window() {
    glfwDestroyWindow(m_window);
}

void Window::set_should_close(bool should_close) {
    glfwSetWindowShouldClose(m_window, should_close);
}

bool Window::should_close() const {
    return glfwWindowShouldClose(m_window);
}

GLFWwindow* Window::get_window() const {
    return m_window;
}
