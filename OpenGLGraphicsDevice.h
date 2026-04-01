#pragma once

#include "GraphicsDevice.h"

class OpenGLGraphicsDevice : public GraphicsDevice
{
public:
    OpenGLGraphicsDevice(Window& window);
    virtual ~OpenGLGraphicsDevice();

    void BeginFrame() override;
    void EndFrame() override;
    void Clear(float r, float g, float b, float a) override;

private:
    Window& m_window;
};
