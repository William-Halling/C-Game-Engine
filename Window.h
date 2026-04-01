#pragma once

#include <string>

struct GLFWwindow;

class Window
{
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    void PollEvents();
    bool ShouldClose() const;

    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }
    GLFWwindow* GetNativeWindow() const { return m_window; }

    // Make OpenGL context current for this window
    void MakeContextCurrent();

private:
    GLFWwindow* m_window = nullptr;
    int m_width, m_height;
    std::string m_title;

    static void ErrorCallback(int error, const char* description);
};
