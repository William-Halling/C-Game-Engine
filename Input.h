#pragma once

#include <unordered_map>

class Window; // forward

class Input
{
public:
    Input();
    ~Input() = default;

    // Call once per frame to update internal state
    void Update();

    // Keyboard
    bool IsKeyPressed(int key) const;   // key is GLFW key code
    bool IsKeyJustPressed(int key) const;

    // Mouse
    bool IsMouseButtonPressed(int button) const;
    bool IsMouseButtonJustPressed(int button) const;
    void GetMousePosition(double& x, double& y) const;

    // Gamepad (optional)
    bool IsGamepadConnected(int id) const;

private:
    // Current and previous frame key states
    std::unordered_map<int, bool> m_keyStates;
    std::unordered_map<int, bool> m_prevKeyStates;

    double m_mouseX = 0.0, m_mouseY = 0.0;
};
