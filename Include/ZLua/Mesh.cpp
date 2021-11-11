#include "Mesh.h"

Mesh::Mesh(std::vector<float> vertexes, unsigned int shader_) 
{
	vertices = vertexes;
	cout << vertices.back();
	shader = Shader(shader_);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

std::vector<float> fromList(float verts[])
{
	std::vector<float> vector;
	for (int i = 0; i < sizeof(verts)/sizeof(float); i++)
	{
		vector.push_back(verts[i]);
	}
	return vector;
}

ZLUA_STATUS Mesh::draw()
{
	shader.use();
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	return ZLUA_STATUS::ZLUA_OK;
}