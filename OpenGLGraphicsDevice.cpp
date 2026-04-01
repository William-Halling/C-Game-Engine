#include "OpenGLGraphicsDevice.h"
#include <glad/glad.h>

OpenGLGraphicsDevice::OpenGLGraphicsDevice(Window& window)
    : m_window(window)
{
    // Ensure context is current (already done by Window)
    // Set up OpenGL state
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

OpenGLGraphicsDevice::~OpenGLGraphicsDevice()
{
}

void OpenGLGraphicsDevice::BeginFrame()
{
    // Nothing special for OpenGL
}

void OpenGLGraphicsDevice::EndFrame()
{
    m_window.GetNativeWindow() ? glfwSwapBuffers(m_window.GetNativeWindow()) : void();
}

void OpenGLGraphicsDevice::Clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
