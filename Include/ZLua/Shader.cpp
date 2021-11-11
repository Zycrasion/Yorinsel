#include "Shader.h"

using namespace std;

Shader::Shader(unsigned int ID_) 
{
	ID = ID_;
}

Shader::Shader()
{
	ID = 0;
}

Shader::Shader(const char* fragmentPath, const char* vertexPath)
{
	string fragmentSource;
	string vertexSource;
	ifstream fShaderFile;
	ifstream vShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	bool failed = false;

	try
	{
		fShaderFile.open(fragmentPath);
		vShaderFile.open(vertexPath);
		stringstream vShaderStream, fShaderStream;
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		vShaderFile.close();
		fShaderFile.close();
		fragmentSource = fShaderStream.str();
		vertexSource = vShaderStream.str();
	}
	catch (ifstream::failure e)
	{
		cout << "ERROR::SHADER::FILE UNABLE TO READ ONE OR MORE SHADER FILES\n";
		failed = true;
	}

	if (!failed)
	{
		const char* fShaderCode = fragmentSource.c_str();
		const char* vShaderCode = vertexSource.c_str();

		unsigned int fShader, vShader;
		int success;
		char infoLog[512];

		vShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vShader, 1, &vShaderCode, NULL);
		glCompileShader(vShader);
		// Getting Info Log
		glGetShaderiv(vShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vShader, 512, NULL, infoLog);
			cout << "ERROR::SHADER::COMPILE UNABLE TO COMPILE VERTEX SHADER. INFO LOG:\n" << infoLog << "\n";
		}
		fShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fShader, 1, &fShaderCode, NULL);
		glCompileShader(fShader);
		glGetShaderiv(fShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fShader, 512, NULL, infoLog);
			cout << "ERROR::SHADER::COMPILE UNABLE TO COMPILE FRAGMENT SHADER. INFO LOG:\n" << infoLog << "\n";
		}

		ID = glCreateProgram();
		glAttachShader(ID, vShader);
		glAttachShader(ID, fShader);
		glLinkProgram(ID);
		glGetProgramiv(ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(ID, 512, NULL, infoLog);
			cout << "ERROR::SHADER::LINK UNABLE TO LINK SHADER PROGRAM. INFO LOG:\n" << infoLog << "\n";
		}

		glDeleteShader(vShader);
		glDeleteShader(fShader);
	}
}

void Shader::use()
{
	glUseProgram(ID);
}

void Shader::setBool(const string& name, bool value)
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void Shader::setInt(const string& name, int value)
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const string& name, float value)
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

unsigned int Shader::getID()
{
	return ID;
}
void Shader::setID(unsigned int ID_)
{
	ID = ID_;
}