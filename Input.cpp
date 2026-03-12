#include "Input.h"
#include <GLFW/glfw3.h>

Input::Input()
{
    // Could register callbacks with glfwSetKeyCallback, etc.
    // For simplicity we'll poll in Update().
}


void Input::Update()
{
      // Save previous states
    m_prevKeyStates = m_keyStates;


    // Poll keyboard (example: all keys up to GLFW_KEY_LAST)
    for (int key = GLFW_KEY_SPACE; key <= GLFW_KEY_LAST; ++key)
    {
        bool pressed = (glfwGetKey(glfwGetCurrentContext(), key) == GLFW_PRESS);
        m_keyStates[key] = pressed;
    }


    // Poll mouse buttons
    for (int btn = GLFW_MOUSE_BUTTON_1; btn <= GLFW_MOUSE_BUTTON_LAST; ++btn)
    {
        bool pressed = (glfwGetMouseButton(glfwGetCurrentContext(), btn) == GLFW_PRESS);
        m_keyStates[btn] = pressed; // store in same map with negative indices? Better separate.
        
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
