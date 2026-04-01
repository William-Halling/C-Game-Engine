#pragma once

#include <string>
#include <glm/glm.hpp>

class Shader
{
public:
    Shader(const std::string& vertexSource, const std::string& fragmentSource);
    ~Shader();

    void Use() const;

    void SetUniform(const std::string& name, const glm::mat4& mat);
    void SetUniform(const std::string& name, const glm::vec3& vec);
    void SetUniform(const std::string& name, float value);
    void SetUniform(const std::string& name, int value);

private:
    unsigned int m_programID;
    int GetUniformLocation(const std::string& name) const;
};
