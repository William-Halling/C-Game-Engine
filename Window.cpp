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
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // For Vulkan; adjust for OpenGL

    m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!m_window)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create window");
    }

    // Store pointer to this instance for callbacks
    glfwSetWindowUserPointer(m_window, this);
}


Window::~Window()
{
  if (m_window)
  {      
    glfwDestroyWindow(m_window);
  }
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


void Window::ErrorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
}
