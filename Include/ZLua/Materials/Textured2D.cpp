#include "Textured2D.h"

Textured2D::Textured2D(const char* texturePath_) : Material(0.0f, 0.0f, 0.0f,
	"./Include/ZLua/Materials/Shaders/Textured2D/fragment.glsl",
	"./Include/ZLua/Materials/Shaders/Textured2D/vertex.glsl")
{
	texturePath = texturePath_;
	texture = 0;
}

void Textured2D::init()
{
	
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	//Setting Texture Wrapping Method (DEFUALT MIRRORED REPEAT)
	//TODO MAKE TEXTURE WRAPPING DYNAMIC
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	//Texture Filtering Methods
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//MIPMAP Filtering Methods
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Loading textures
	int width, height, nrChannels;
	unsigned char* data = stbi_load(texturePath, &width, &height, &nrChannels, 0);
	//Generating Textures
	if (data)
	{
		glTexImage2D(texture, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(texture);
	}
	else
	{
		cout << "ERROR::MATERIAL::TEXTURE2D Unable to read texture file.";
	}
	//freeing ram
	stbi_image_free(&data);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

void Textured2D::apply()
{
	shader.use();
	glBindTexture(GL_TEXTURE_2D, texture);

}