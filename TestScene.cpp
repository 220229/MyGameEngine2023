#include "TestScene.h"

TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene")
{
}

void TestScene::Initialize()
{
}

void TestScene::Update()
{
	GameObject* dbgTest = FindObject("SceneManager");
}

void TestScene::Draw()
{
}

void TestScene::Release()
{
}