#pragma once

#include <string>

struct GLFWwindow; // Forward declaration

class Window
{
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    // Delete copy/move
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    void PollEvents();
    bool ShouldClose() const;

    // Accessors
    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }
    GLFWwindow* GetNativeWindow() const { return m_window; }

private:
    GLFWwindow* m_window = nullptr;
    int m_width, m_height;
    std::string m_title;

    static void ErrorCallback(int error, const char* description);
};
