#pragma once

#include <memory>
#include <chrono>

class Application;
class Window;
class Input;
class GraphicsDevice;
class ResourceManager;
class Scene;

class Engine
{
public:
    Engine();
    ~Engine();

    // Initialize subsystems and run the game.
    int Run(std::unique_ptr<Application> app);

    // Accessors for subsystems (used by Application)
    Window& GetWindow() { return *m_window; }
    Input& GetInput() { return *m_input; }
    GraphicsDevice& GetGraphicsDevice() { return *m_graphicsDevice; }
    ResourceManager& GetResourceManager() { return *m_resourceManager; }
    Scene& GetScene() { return *m_scene; }

    // Engine is non-copyable
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

private:
    void OnInit();
    void OnUpdate(float deltaTime);
    void OnShutdown();

    std::unique_ptr<Application> m_app;
    std::unique_ptr<Window> m_window;
    std::unique_ptr<Input> m_input;
    std::unique_ptr<GraphicsDevice> m_graphicsDevice;
    std::unique_ptr<ResourceManager> m_resourceManager;
    std::unique_ptr<Scene> m_scene;

    bool m_running = true;
    using Clock = std::chrono::high_resolution_clock;
    Clock::time_point m_lastFrameTime;
};
