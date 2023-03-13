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
		marble->EmplaceComponent<RigidbodyComponent>(SPHERE_SHAPE, 10.0f);
		marble->AddScript<MarbleControllerScript>();

		GameObject camera = scn.CreateGameObject("Camera", marble);
		camera->EmplaceComponent<CameraComponent>();
		camera->AddScript<OrbitCameraScript>();
		camera->RegisterToScene();

		return marble;
	}
};

#endif