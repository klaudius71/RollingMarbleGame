#include "RollingMarble.h"
#include "Level1.h"

RollingMarble::RollingMarble(const int window_width, const int window_height, const char* const icon_path)
	: Glacier::Application(window_width, window_height, icon_path)
{
}

void RollingMarble::LoadResources()
{
	ModelLoader::Load("Sphere", 20, 20);
	ModelLoader::Load("Vampire", "vampire2.glacier", true);
	ModelLoader::Load("Plane", 1000, 10, 10);

	TextureLoader::Load("default", "default.tga");
	TextureLoader::Load("default_normal", glm::vec4{ 0.5f, 0.5f, 1.0f, 1.0f });
	TextureLoader::Load("Rock", "strata-rock-2_albedo.tga");
	TextureLoader::Load("RockNormal", "strata-rock-2_normal-ogl.tga");

	FontLoader::Load("Times40", "times.ttf", 40);
	FontLoader::Load("CascadiaMono20", "CascadiaMono.ttf", 20);

	SceneManager::SetNextScene(new Level1);
}
