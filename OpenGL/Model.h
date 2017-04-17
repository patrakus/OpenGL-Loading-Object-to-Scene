#pragma once

#include <GL/glew.h>

#include "ShaderProgram.h"
#include "Mesh.h"

#include <vector>
#include <string>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Model
{
public:
	Model(GLchar* path)
	{
		this->loadModel(path);
	}
	void Draw(ShaderProgram shader);

private:
	// Model Data
	std::vector<Texture> textures_loaded;
	std::vector<Mesh> meshes;
	std::string directory;
	
	// Functions
	void loadModel(std::string path);
	void processNode(aiNode* node, const aiScene* scene);
	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);
	GLint TextureFromFile(const char* path, std::string directory);

};

