#include "TestScript.h"

TestScript::TestScript()
	: Script("TestScript")
{
}

void TestScript::OnUpdate(float dt)
{
	TransformComponent& transform = GetGameObject()->GetComponent<TransformComponent>();
	transform.rotation().y += dt;
}