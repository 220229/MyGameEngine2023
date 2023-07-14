#include "Player.h"
#include "Engine/Fbx.h"
#include "ChildObject.h"
#include "Engine/Input.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"), pFbx(nullptr)
{
}

Player::~Player()
{

}

void Player::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("Assets/oden.fbx");
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
		GameObject* pBullet = Instantiate<ChildObject>(pParent_);	//ŽÀ‘Ì‚Ì¶¬
		pBullet->SetPosition(this->transform_.position_);	//‰ŠúˆÊ’u‚ÌŽw’è
	}
}

void Player::Draw()
{
	pFbx->Draw(transform_);
}

void Player::Release()
{
}
