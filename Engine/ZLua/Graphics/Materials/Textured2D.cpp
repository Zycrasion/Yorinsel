#include "Textured2D.h"
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#endif

Textured2D::Textured2D(const char* texturePath_) : Material("./Engine/ZLua/Graphics/Materials/Shaders/Textured2D/fragment.glsl",
	"./Engine/ZLua/Graphics/Materials/Shaders/Textured2D/vertex.glsl")
{
	texturePath = texturePath_;
	texture = 0;
}

void Textured2D::init()
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	printf("texture:%i ", texture);
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
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		printf("%i %i %i %i", (int)data[0], (int)data[1], (int)data[2], (int)data[3]);
		printf("\n width: %i, height: %i, channels: %i", width, height, nrChannels);
		//stbi_image_free(&data);
	}
	else
	{
		cout << "ERROR::MATERIAL::TEXTURE2D Unable to read texture file.";
	} 
	//freeing ram
	
}

void Textured2D::apply(glm::mat4 trans)
{
	glBindTexture(GL_TEXTURE_2D, texture);
	shader.use();
	shader.setMat4("transform",trans);
}