#include "Engine.h"
#include "Application.h"
#include "Window.h"
#include "Input.h"
#include "GraphicsDevice.h"
#include "ResourceManager.h"
#include "Scene.h"

#include <iostream>

Engine::Engine() = default;
Engine::~Engine() = default;


int Engine::Run(std::unique_ptr<Application> app)
{
    m_app = std::move(app);
    OnInit();

    m_lastFrameTime = Clock::now();
    while (m_running)
    {
        auto currentTime = Clock::now();
        float deltaTime = std::chrono::duration<float>(currentTime - m_lastFrameTime).count();
        m_lastFrameTime = currentTime;

        // Poll OS events
        m_window->PollEvents();

        // Update input state
        m_input->Update();

        // Game update
        OnUpdate(deltaTime);

        // Render
        m_graphicsDevice->BeginFrame();
        m_scene->Render(*m_graphicsDevice);
        m_graphicsDevice->EndFrame();

      
        // If window close requested, exit
        if (m_window->ShouldClose())
            m_running = false;
    }

    OnShutdown();
    return 0;
}


void Engine::OnInit()
{
    m_window = std::make_unique<Window>("Game Engine", 1280, 720);
    m_input = std::make_unique<Input>();
    m_graphicsDevice = std::make_unique<GraphicsDevice>(*m_window);
    m_resourceManager = std::make_unique<ResourceManager>();
    m_scene = std::make_unique<Scene>();

    m_app->OnInit(*this);
}


void Engine::OnUpdate(float deltaTime)
{
    m_app->OnUpdate(*this, deltaTime);
    m_scene->Update(deltaTime);
}

void Engine::OnShutdown()
{
    m_app->OnShutdown(*this);
}
