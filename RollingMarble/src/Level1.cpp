#include "Level1.h"
#include "TestScript.h"

void Level1::InitializeScene()
{
	GameObject camera = CreateGameObject("Camera");
	camera->EmplaceComponent<CameraComponent>(glm::perspective(glm::radians(90.0f), 16.0f / 9.0f, 0.1f, 10000.0f), glm::vec3(0.0f, 10.0f, 10.0f), glm::normalize(glm::vec3(0.0f, -10.0f, -10.0f)));
	camera->RegisterToScene();

	GameObject light = CreateGameObject("Directional Light");
	light->EmplaceComponent<DirectionalLightComponent>(glm::normalize(glm::vec3(-1.0f, -1.0f, -1.0f)));
	light->RegisterToScene();

	GameObject sphere = CreateGameObject("Sphere");
	sphere->EmplaceComponent<MeshComponent>(ModelLoader::Get("Sphere"));
	sphere->EmplaceComponent<MaterialComponent>(VertexTypes::PhongADS(), TextureLoader::Get("Rock")).norm_tex_id.x = TextureLoader::Get("RockNormal");
	sphere->GetComponent<TransformComponent>().scale() = glm::vec3(5.0f);
	sphere->AddScript<TestScript>();
	sphere->RegisterToScene();
}
