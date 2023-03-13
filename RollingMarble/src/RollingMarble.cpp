#include "RollingMarble.h"
#include "Level1.h"

RollingMarble::RollingMarble(const int window_width, const int window_height, const char* const icon_path)
	: Glacier::Application(window_width, window_height, icon_path)
{
}

void RollingMarble::LoadResources()
{
	ModelLoader::Load("Sphere", 50, 50);
	ModelLoader::Load("Plane", 1000, 10, 10);
	ModelLoader::Load("Cube", PREMADE_MODELS::UNIT_CUBE_REPEAT_TEXTURE);

	TextureLoader::Load("Rock", "strata-rock-2_albedo.tga");
	TextureLoader::Load("RockNormal", "strata-rock-2_normal-ogl.tga");
	TextureLoader::Load("Tile", "tile/xedp5for_2k_diffuse.png");
	TextureLoader::Load("TileNormal", "tile/xedp5for_2k_normal.png");
	TextureLoader::Load("Wood", "wood/hjgjfmu7_2k_diffuse.png");
	TextureLoader::Load("WoodNormal", "wood/hjgjfmu7_2k_normal.png");
	TextureLoader::Load("Sorsele", { "sorsele/posx.jpg", "sorsele/negx.jpg", "sorsele/posy.jpg", "sorsele/negy.jpg", "sorsele/posz.jpg", "sorsele/negz.jpg" });

	FontLoader::Load("CascadiaMono20", "CascadiaMono.ttf", 20);

	SceneManager::SetNextScene(new Level1);
}
