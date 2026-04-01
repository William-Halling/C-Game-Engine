#include "Input.h"
#include <GLFW/glfw3.h>

Input::Input()
{
    // ...
}


void Input::Update()
{
    m_prevKeyStates = m_keyStates;
    m_prevMouseStates = m_mouseStates;

    // Poll keyboard
    for (int key = GLFW_KEY_SPACE; key <= GLFW_KEY_LAST; ++key)
    {
        bool pressed = (glfwGetKey(glfwGetCurrentContext(), key) == GLFW_PRESS);
        m_keyStates[key] = pressed;
    }

    // Poll mouse buttons
    for (int btn = GLFW_MOUSE_BUTTON_1; btn <= GLFW_MOUSE_BUTTON_LAST; ++btn)
    {
        bool pressed = (glfwGetMouseButton(glfwGetCurrentContext(), btn) == GLFW_PRESS);
        m_mouseStates[btn] = pressed;
    }

    glfwGetCursorPos(glfwGetCurrentContext(), &m_mouseX, &m_mouseY);
}


bool Input::IsKeyPressed(int key) const
{
    auto it = m_keyStates.find(key);
    return it != m_keyStates.end() && it->second;
}


bool Input::IsKeyJustPressed(int key) const
{
    auto itCurr = m_keyStates.find(key);
    auto itPrev = m_prevKeyStates.find(key);
    return (itCurr != m_keyStates.end() && itCurr->second) &&
           (itPrev == m_prevKeyStates.end() || !itPrev->second);
}


bool Input::IsMouseButtonPressed(int button) const
{
    auto it = m_mouseStates.find(button);
    return it != m_mouseStates.end() && it->second;
}


bool Input::IsMouseButtonJustPressed(int button) const
{
    auto itCurr = m_mouseStates.find(button);
    auto itPrev = m_prevMouseStates.find(button);
    return (itCurr != m_mouseStates.end() && itCurr->second) &&
           (itPrev == m_prevMouseStates.end() || !itPrev->second);
}


void Input::GetMousePosition(double& x, double& y) const
{
    x = m_mouseX;
    y = m_mouseY;
}
