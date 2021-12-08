/*
Author: Ryan Aloof, Joey de Vries (learnopengl.com)
Description: Handles logic for using and calling into shaders for OpenGL.
             A lot of this code comes from the section on shaders on learnopengl.com
*/

#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    // learnopengl.com constructor for basic shaders
    Shader(const char* vertexPath, const char* fragmentPath);
    unsigned int getShaderId();
    void use();
    void setMatrix4(const std::string& name, glm::mat4 matrix);
    void setVector4f(const std::string& name, glm::vec4 vector);
    void setVector3f(const std::string& name, glm::vec3 vector);

private:
    // shader ID
    unsigned int shaderId;
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    void checkCompileErrors(GLuint shader, std::string type);
    
};

#endif