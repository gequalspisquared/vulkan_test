#include "VulkanApp.hpp"
#include "GLFW/glfw3.h"

// #include <iostream>

static void init_callbacks(VulkanApp* app);

VulkanApp::VulkanApp()
    : m_window(Window(800, 600, "Vulkan App")) {
    init_callbacks(this);
    init_vulkan();
}

VulkanApp::~VulkanApp() {
    glfwTerminate();
}

void VulkanApp::run() {
    while (should_keep_running()) {
        while (!m_paused) {
            // TODO: game/ render logic goes here
        }

        glfwPollEvents();
    }
}

void VulkanApp::process_input(GLFWwindow* w, int key, int scancode, int action, int mod) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        m_running = false;
    }
}

void VulkanApp::init_vulkan() {
}

bool VulkanApp::should_keep_running() const {
    return m_running && !m_window.should_close();
}

GLFWwindow* VulkanApp::_get_glfw_window() const {
    return m_window.get_window();
}

void init_callbacks(VulkanApp* app) {
    GLFWwindow* window = app->_get_glfw_window();
    glfwSetWindowUserPointer(window, app);

    auto key_callback = [](GLFWwindow* w, int key, int scancode, int action, int mod) {
        static_cast<VulkanApp*>(glfwGetWindowUserPointer(w))->process_input(
            w, key, scancode, action, mod
        );
    };

    glfwSetKeyCallback(window, key_callback);
}
