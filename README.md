# My Attempt at a Blizzard C++ Engine

A modular C++ game engine built to high-performance, Blizzard-level standards.  
Supports rendering, input handling, asset management, and core engine systems.  


## Features
- Application and Window management (GLFW)
- Logging system for debug/profiling
- Time and frame management
- Input handling (keyboard, mouse)
- Renderer abstraction (OpenGL/DirectX ready)
- Shader, Texture, and Mesh management
- Camera system (view/projection matrices)
- Centralized AssetManager to prevent duplicate resource loads
- Highly modular architecture for ECS, physics, audio, and networking integration

## Requirements
- C++17 or higher
- GLFW, GLAD, GLM, STB Image
- CMake for building (if you’re using it)
- OpenGL 3.3+
