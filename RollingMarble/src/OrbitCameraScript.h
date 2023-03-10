#ifndef _ORBIT_CAMERA_SCRIPT
#define _ORBIT_CAMERA_SCRIPT

#include "GlacierAPI.h"

class OrbitCameraScript : public Script
{
public:
	OrbitCameraScript();
	~OrbitCameraScript() = default;

	virtual void OnSceneEnter() override;
	virtual void OnUpdate(float dt) override;
	virtual void OnScreenResize(int width, int height) override;

private:
	float CAM_RADIUS = 65.0f;

	GameObject marble;
	glm::vec3 cam_rotation_euler;
};

#endif