#include <glad/gl.h>

#include <fstream>
#include <filesystem>
#include <string>
#include <format>
#include <iostream>

#include "shader.h"

Shader::Shader(const int& Type, const std::string& Path) : m_Id {CreateShader(Type)}
{
	CompileShader(Path);
}

Shader::~Shader()
{
	glDeleteShader(Id());
}

uint32 Shader::CreateShader(const int& Type) const
{
	return glCreateShader(Type);
}

void Shader::CompileShader(const std::string& Path) const
{
	const std::string shaderSourceStr {Source(Path)};

	const char* const shaderSource {shaderSourceStr.c_str()};

	glShaderSource(m_Id, 1, &shaderSource, nullptr);	

	glCompileShader(Id());

	int successfulCompile {};

	glGetShaderiv(Id(), GL_COMPILE_STATUS, &successfulCompile);

	if (!successfulCompile)
	{
		char log[512];

		glGetShaderInfoLog(Id(), sizeof(log), nullptr, log);

		std::cout << "Shader failed to compile. " << log << std::endl;
	}
}

std::string Shader::Source(const std::string& ShaderName) const
{
	const std::filesystem::path exeDirectoryPath {std::filesystem::current_path()};

	if (!exeDirectoryPath.has_parent_path())
	{
		return "ERROR: Build directory path not found.";
	}

	const std::filesystem::path buildDirectoryPath {exeDirectoryPath.parent_path()};

	if (!buildDirectoryPath.has_parent_path())
	{
		return "ERROR: Project root directory path not found.";
	}

	const std::filesystem::path projectRootDirectoryPath {buildDirectoryPath.parent_path()};
	
	// WRONG check for relative path exsistance
	const std::string shaderDirectoryRelativePath {std::format("res\\shader\\{0}", ShaderName)};

	const std::filesystem::path shaderDirectoryPath {projectRootDirectoryPath / shaderDirectoryRelativePath};

	if (!std::filesystem::exists(shaderDirectoryPath))
	{
		return "ERROR: Shader directory path not found";
	}

	std::ifstream shaderSource {shaderDirectoryPath};

	if (shaderSource.is_open())
	{
		std::string fileContents {};
		std::string line {};

		while (std::getline(shaderSource, line))
		{
			if (line == "")
			{
				fileContents += "\n";

				continue;
			}

			fileContents += line;
		}

		shaderSource.close();

		return fileContents;
	}
	else
	{
		std::cout << "Failed to load shader source" << std::endl;

		return "";
	}
}
