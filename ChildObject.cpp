#include "ChildObject.h"
#include "Engine/Fbx.h"
#include"Engine/Input.h"

ChildObject::ChildObject(GameObject* parent) : GameObject(parent, "Player"), pFbx(nullptr)
{
}

ChildObject::~ChildObject()
{

}

void ChildObject::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("Assets/oden.fbx");



	this->transform_.position_.x = 4.0f;
	this->transform_.scale_ = { 0.1f,0.1f ,0.1f };
}

void ChildObject::Update()
{
	transform_.position_.z ++;
	if (transform_.position_.z > 50) KillMe();
}

void ChildObject::Draw()
{
	pFbx->Draw(transform_);
}

void ChildObject::Release()
{

}

