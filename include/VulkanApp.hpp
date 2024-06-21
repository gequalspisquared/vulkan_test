#pragma once

#include "Window.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <cstdlib>

class VulkanApp {
public:
    VulkanApp();
    ~VulkanApp();

    void run();
    void process_input(GLFWwindow* w, int key, int scancode, int action, int mod);

    GLFWwindow* _get_glfw_window() const;

private:
    Window m_window;
    bool m_running = true;
    bool m_paused = false;

    void init_vulkan();

    bool should_keep_running() const;
};
