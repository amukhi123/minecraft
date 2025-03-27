#pragma once

#include <filesystem>
#include <memory>

class ProjectFileSystem final
{
public:
	static ProjectFileSystem* Instance();

	static std::filesystem::path ProjectRootDirectoryPath();

	static std::filesystem::path ResourceDirectoryPath();

	static std::filesystem::path TextureDirectoryPath();

	static std::filesystem::path GetTextureFilePath(const std::string& FileName);

	static std::filesystem::path ShaderDirectoryPath();

	static std::filesystem::path GetShaderFilePath(const std::string& FileName);
private:
	static std::unique_ptr<ProjectFileSystem> s_ProjectFileSystem;
};

inline std::unique_ptr<ProjectFileSystem> ProjectFileSystem::s_ProjectFileSystem {nullptr};
