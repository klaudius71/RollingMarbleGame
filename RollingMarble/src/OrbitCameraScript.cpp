#include "OrbitCameraScript.h"

OrbitCameraScript::OrbitCameraScript()
	: Script("OrbitCameraScript"), CAM_RADIUS(65.0f), cam_rotation_euler{ glm::radians(-40.0f), 0.0f, 0.0f }
{
}

void OrbitCameraScript::OnSceneEnter()
{
	marble = GetGameObject()->GetParent();
	assert(!marble.isExpired());
}
void OrbitCameraScript::OnUpdate(float dt)
{
	// Camera Movement
	if (Input::GetMouseButtonState(GLACIER_MOUSE::RIGHT_MOUSE_BUTTON))
	{
		const glm::vec2& mouse_delta = Input::GetMouseDeltaPosition();
		cam_rotation_euler.x += mouse_delta.y * dt;
		cam_rotation_euler.y -= mouse_delta.x * dt;
	}
	else
	{
		if (Input::GetKeyDown(GLACIER_KEY::KEY_ARROW_UP))
			cam_rotation_euler.x += dt * 2.0f;
		else if (Input::GetKeyDown(GLACIER_KEY::KEY_ARROW_DOWN))
			cam_rotation_euler.x -= dt * 2.0f;
		if (Input::GetKeyDown(GLACIER_KEY::KEY_ARROW_LEFT))
			cam_rotation_euler.y += dt * 2.0f;
		else if (Input::GetKeyDown(GLACIER_KEY::KEY_ARROW_RIGHT))
			cam_rotation_euler.y -= dt * 2.0f;
	}
	if (Input::GetKeyDown(GLACIER_KEY::KEY_KP_ADD))
		CAM_RADIUS -= dt * 20.0f;
	else if(Input::GetKeyDown(GLACIER_KEY::KEY_KP_SUBTRACT))
		CAM_RADIUS += dt * 20.0f;

	// Camera Clamping
	if (cam_rotation_euler.x < glm::radians(-80.0f))
		cam_rotation_euler.x = glm::radians(-80.0f);
	else if (cam_rotation_euler.x > glm::radians(7.5f))
		cam_rotation_euler.x = glm::radians(7.5f);

	const TransformComponent& marble_transform = marble->GetComponent<TransformComponent>();
	CameraComponent& camera = GetGameObject()->GetComponent<CameraComponent>();
	const float cos_pitch = cosf(cam_rotation_euler.x);
	const glm::vec3 camera_offset = CAM_RADIUS * glm::vec3(sinf(cam_rotation_euler.y) * cos_pitch, sinf(cam_rotation_euler.x), cosf(cam_rotation_euler.y) * cos_pitch);
	camera.cam_pos = marble_transform.GetWorldPosition() - camera_offset;
	camera.cam_dir = glm::normalize(marble_transform.GetWorldPosition() - camera.cam_pos);
}

void OrbitCameraScript::OnScreenResize(int width, int height)
{
	CameraComponent::ResetProjectionToSize(GetGameObject()->GetComponent<CameraComponent>(), width, height);
}
