#pragma once

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <vector>

#include "ShaderProgram.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

struct Vertex
{
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

struct Texture
{
	GLuint id;
	std::string type;
	aiString path;
};

class Mesh
{
public:
	/* Mesh Data */
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
	std::vector<Texture> textures;

	/* Funtions */
	Mesh(std::vector<Vertex> &vertices, std::vector<GLuint> &indices, std::vector<Texture> &textures);
	void Draw(ShaderProgram &shader);

private:
	// Render Data
	GLuint VAO, VBO, EBO;
	
	// Functions
	void setupMesh();
};

