#pragma once

#include <unordered_map>
#include <string>
#include <memory>

class Shader; // forward

class ResourceManager
{
public:
    ResourceManager();
    ~ResourceManager();

    // Shader management
    std::shared_ptr<Shader> LoadShader(const std::string& name,
                                       const std::string& vertexPath,
                                       const std::string& fragmentPath);

    std::shared_ptr<Shader> GetShader(const std::string& name);

    // Later: texture, mesh loading...

private:
    std::unordered_map<std::string, std::shared_ptr<Shader>> m_shaders;
};
