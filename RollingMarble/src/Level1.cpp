#include "Level1.h"
#include "TestScript.h"
#include "MarblePrefab.h"

void Level1::InitializeScene()
{
	GameObject light = CreateGameObject("Directional Light");
	light->EmplaceComponent<DirectionalLightComponent>(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));
	light->RegisterToScene();

	GameObject ball = CreatePrefab<MarblePrefab>();
	ball->GetComponent<RigidbodyComponent>().SetWorldPosition(glm::vec3(0.0f, 50.0f, 0.0f));
	ball->RegisterToScene();

	GameObject plane = CreateGameObject("Plane");
	plane->EmplaceComponent<MeshComponent>(ModelLoader::Get("Plane"));
	plane->EmplaceComponent<MaterialComponent>(VertexTypes::PhongADS(), TextureLoader::Get("Rock"));
	plane->EmplaceComponent<RigidbodyComponent>(PLANE_SHAPE).SetWorldPosition(glm::vec3(0.0f));
	plane->RegisterToScene();
}
