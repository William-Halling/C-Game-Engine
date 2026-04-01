#include "ResourceManager.h"
#include "Shader.h"

ResourceManager::ResourceManager() = default;
ResourceManager::~ResourceManager() = default;

std::shared_ptr<Shader> ResourceManager::LoadShader(const std::string& name,
                                                    const std::string& vertexPath,
                                                    const std::string& fragmentPath)
{
    auto shader = std::make_shared<Shader>(vertexPath, fragmentPath);
    m_shaders[name] = shader;
    return shader;
}

std::shared_ptr<Shader> ResourceManager::GetShader(const std::string& name)
{
    auto it = m_shaders.find(name);
    if (it != m_shaders.end())
        return it->second;
    return nullptr;
}
