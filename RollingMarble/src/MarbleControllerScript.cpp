#include "MarbleControllerScript.h"

MarbleControllerScript::MarbleControllerScript()
	: Script("MarbleControllerScript")
{
}

void MarbleControllerScript::OnSceneEnter()
{
	camera = GetGameObject()->GetChildren().front();
	assert(!camera.isExpired());
}
void MarbleControllerScript::OnUpdate(float dt)
{
	RigidbodyComponent& rigidbody = GetGameObject()->GetComponent<RigidbodyComponent>();
	CameraComponent& cam = camera->GetComponent<CameraComponent>();

	// Movement
	const glm::vec3 fwd(glm::normalize(glm::vec3{ cam.cam_dir.z, 0.0f, -cam.cam_dir.x }));
	const glm::vec3 right(glm::cross(fwd, glm::vec3(0.0f, 1.0f, 0.0f)));

	if (Input::GetKeyDown(GLACIER_KEY::KEY_W))
		rigidbody.ApplyTorqueImpulse(fwd * 5000.0f);
	else if (Input::GetKeyDown(GLACIER_KEY::KEY_S))
		rigidbody.ApplyTorqueImpulse(fwd * -5000.0f);
	if (Input::GetKeyDown(GLACIER_KEY::KEY_A))
		rigidbody.ApplyTorqueImpulse(right * -5000.0f);
	else if (Input::GetKeyDown(GLACIER_KEY::KEY_D))
		rigidbody.ApplyTorqueImpulse(right * 5000.0f);

	static bool key_pressed = false;
	bool space_down = Input::GetKeyDown(GLACIER_KEY::KEY_SPACE);
	if (space_down && !key_pressed)
	{
		key_pressed = true;
		rigidbody.ApplyCentralImpulse(glm::vec3(0.0f, 50000.0f, 0.0f));
	}
	else if (!space_down)
	{
		key_pressed = false;
	}

	//const Font& font = FontLoader::Get("CascadiaMono20");
	//const float y_offset = (float)Renderer::GetMainFramebuffer().GetSize().y;
	//Renderer2D::PrintText(font, 10.0f, y_offset - 20.0f, Colors::Black, "FPS: %.f", 1.0f / TimeManager::GetDeltaTime());
	//Renderer2D::PrintText(font, 10.0f, y_offset - 50.0f, Colors::Black, "Movement Controls:");
	//Renderer2D::PrintText(font, 10.0f, y_offset - 80.0f, Colors::Black, "Ball: WASD");
	//Renderer2D::PrintText(font, 10.0f, y_offset - 110.f, Colors::Black, "Camera: RMB + Mouse");
}