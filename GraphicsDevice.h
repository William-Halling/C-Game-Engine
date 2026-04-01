#pragma once

#include "Window.h"

class GraphicsDevice
{
public:
    virtual ~GraphicsDevice() = default;
    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;
    virtual void Clear(float r, float g, float b, float a) = 0;
    // More render commands...
};
