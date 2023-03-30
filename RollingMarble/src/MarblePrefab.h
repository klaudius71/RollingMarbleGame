#ifndef _BALL_PREFAB
#define _BALL_PREFAB

#include "GlacierAPI.h"
#include "MarbleControllerScript.h"
#include "OrbitCameraScript.h"

class MarblePrefab : public Prefab
{
public:
	virtual GameObject ApplyPrefab(Scene& scn) override
	{
		GameObject marble = scn.CreateGameObject("Marble");
		marble->EmplaceComponent<MeshComponent>(ModelLoader::Get("Sphere"));
		marble->EmplaceComponent<MaterialComponent>(VertexTypes::PhongADS(), TextureLoader::Get("Wood")).norm_tex_id.x = TextureLoader::Get("WoodNormal");
		marble->GetComponent<TransformComponent>().scale() = glm::vec3(10.0f);
		marble->EmplaceComponent<SphereColliderComponent>(10.0f, 50.0f);
		marble->AddScript<MarbleControllerScript>();

		GameObject camera = scn.CreateGameObject("Camera", marble);
		const glm::ivec2& screen_size = Renderer::GetMainFramebuffer().GetSize();
		camera->EmplaceComponent<CameraComponent>(glm::perspective(glm::radians(90.0f), (float)screen_size.x / screen_size.y, 0.1f, 10000.0f));
		camera->AddScript<OrbitCameraScript>();
		camera->RegisterToScene();

		return marble;
	}
};

#endif