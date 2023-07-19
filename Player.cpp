#include "Player.h"
#include "Engine/Fbx.h"
#include "ChildObject.h"
#include "Engine/Input.h"
#include "Engine/Model.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"),hModel(-1)
{
}

Player::~Player()
{

}

void Player::Initialize()
{
	hModel = Model::Load("Assets/Oden.fbx");

	this->transform_.scale_.x = 0.5;
	this->transform_.scale_.y = 0.5;
	this->transform_.scale_.z = 0.5;
	
	
}

void Player::Update()
{
	this->transform_.rotate_.y ++;
	if (Input::IsKey(DIK_D)) {
		transform_.position_.x += 0.1f;
	}

	if (Input::IsKey(DIK_A)) {
		transform_.position_.x -= 0.1f;
	}

	if (Input::IsKeyDown(DIK_SPACE)) {
		GameObject* pBullet = Instantiate<ChildObject>(pParent_);	//À‘Ì‚Ì¶¬
		pBullet->SetPosition(this->transform_.position_);	//‰ŠúˆÊ’u‚Ìw’è
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel, transform_);
}

void Player::Release()
{
}
