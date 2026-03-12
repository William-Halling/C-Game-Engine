#pragma once

class Engine;

class Application
{
  public:
    virtual ~Application() = default;

    virtual void OnInit(Engine& engine) = 0;
    virtual void OnUpdate(Engine& engine, float deltaTime) = 0;
    virtual void OnShutdown(Engine& engine) = 0;
};
