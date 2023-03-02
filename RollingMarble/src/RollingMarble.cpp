#include "RollingMarble.h"

RollingMarble::RollingMarble(const int window_width, const int window_height, const char* const icon_path)
	: Glacier::Application(window_width, window_height, icon_path)
{
}

void RollingMarble::LoadResources()
{
	ModelLoader::Load("Vampire", "vampire2.glacier", true);
}
