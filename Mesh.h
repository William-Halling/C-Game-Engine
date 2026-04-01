#pragma once

#include <vector>
#include <glm/glm.hpp>

class Shader;

class Mesh
{
public:
    Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices);
    ~Mesh();

    void Draw(Shader& shader);

private:
    unsigned int m_VAO, m_VBO, m_EBO;
    unsigned int m_indexCount;
};
