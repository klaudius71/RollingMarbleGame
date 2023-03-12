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

private:
	const float CAM_RADIUS = 65.0f;

	GameObject marble;
	glm::vec3 cam_rotation_euler{ 0.0f, 0.0f, 0.0f };
};

#endif