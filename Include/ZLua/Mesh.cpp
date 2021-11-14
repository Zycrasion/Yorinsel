#include "Mesh.h"

Mesh::Mesh(std::vector<float> vertexes, Material mat_) : mat((const Material&) mat_)
{
	vertices = vertexes;
	mat = mat_;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);
	
	mat_.init();
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}
ZLUA_STATUS Mesh::draw()
{
	mat.apply();
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, vertices.size(), GL_UNSIGNED_INT, 0);
	return ZLUA_STATUS::ZLUA_OK;
}