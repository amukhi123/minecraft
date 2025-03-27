#include <cassert>

#include "util/project_file_system.h"

ProjectFileSystem* ProjectFileSystem::Instance()
{
	if (!s_ProjectFileSystem)
	{
		s_ProjectFileSystem = std::unique_ptr<ProjectFileSystem>(new ProjectFileSystem);
	}

	assert(s_ProjectFileSystem);

	return s_ProjectFileSystem.get();
}


std::filesystem::path ProjectFileSystem::ProjectRootDirectoryPath()
{
	const std::filesystem::path exeDirectoryPath {std::filesystem::current_path()};

	assert(exeDirectoryPath.has_parent_path());

	const std::filesystem::path buildDirectoryPath {exeDirectoryPath.parent_path()};

	assert(buildDirectoryPath.has_parent_path());

	const std::filesystem::path projectRootDirectoryPath {buildDirectoryPath.parent_path()};

	assert(std::filesystem::exists(projectRootDirectoryPath));

	return projectRootDirectoryPath;
}

std::filesystem::path ProjectFileSystem::ResourceDirectoryPath()
{
	const std::filesystem::path resourceDirectoryPath {ProjectRootDirectoryPath().string() + "\\res\\"};

	assert(std::filesystem::exists(resourceDirectoryPath));

	return resourceDirectoryPath;
}

std::filesystem::path ProjectFileSystem::TextureDirectoryPath()
{
	const std::filesystem::path textureDirectoryPath {ResourceDirectoryPath().string() + "texture\\"};

	assert(std::filesystem::exists(textureDirectoryPath));

	return textureDirectoryPath;
}

std::filesystem::path ProjectFileSystem::GetTextureFilePath(const std::string& FileName)
{
	const std::filesystem::path textureFilePath {TextureDirectoryPath().string() + FileName};

	assert(std::filesystem::exists(textureFilePath));
	
	return textureFilePath;
}

std::filesystem::path ProjectFileSystem::GetShaderFilePath(const std::string& FileName)
{
	const std::filesystem::path shaderFilePath {ShaderDirectoryPath().string() + FileName};

	assert(std::filesystem::exists(shaderFilePath));
	
	return shaderFilePath;
}

std::filesystem::path ProjectFileSystem::ShaderDirectoryPath()
{
	const std::filesystem::path shaderDirectoryPath {ResourceDirectoryPath().string() + "shader\\"};

	assert(std::filesystem::exists(shaderDirectoryPath));

	return shaderDirectoryPath;
}
