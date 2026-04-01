#include "Window.h"
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <iostream>

Window::Window(const std::string& title, int width, int height)
    : m_width(width), m_height(height), m_title(title)
{
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    glfwSetErrorCallback(ErrorCallback);

    // OpenGL hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!m_window)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create window");
    }

    glfwSetWindowUserPointer(m_window, this);
    MakeContextCurrent(); // context is now current
}


Window::~Window()
{
    if (m_window)
        glfwDestroyWindow(m_window);
    glfwTerminate();
}


void Window::PollEvents()
{
    glfwPollEvents();
}


bool Window::ShouldClose() const
{
    return glfwWindowShouldClose(m_window);
}


void Window::MakeContextCurrent()
{
    glfwMakeContextCurrent(m_window);
}


void Window::ErrorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
}
