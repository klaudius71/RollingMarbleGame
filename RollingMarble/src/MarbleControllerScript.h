#ifndef _MARBLE_CONTROLLER_SCRIPT
#define _MARBLE_CONTROLLER_SCRIPT

#include "GlacierAPI.h"

class MarbleControllerScript : public Script
{
public:
	MarbleControllerScript();
	~MarbleControllerScript() = default;

	virtual void OnSceneEnter() override;
	virtual void OnUpdate(float dt) override;

private:
	GameObject camera;
};

#endif