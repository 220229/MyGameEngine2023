#include "Stage.h"
#include "Engine/Model.h"

//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModel_(-1)
{
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
    string modelname[] = {
        "BoxDefault.fbx",
        "BoxBrick.fbx",
        "BoxGrass.fbx",
        "BoxSand.fbx",
        "BoxWater.fbx",
    };
    string fname_base = "assets/";

    //モデルデータのロード
    for (int i = 0; i < MODEL_NUM; i++)
    {
        hModel_[i] = Model::Load(fname_base + modelname[i]);
        assert(hModel_[i] >= 0);
    }
}

//更新
void Stage::Update()
{
}

//描画
void Stage::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
    for (int x = 0; x < 15; x++)
    {
        for (int z = 0; z < 15; z++)
        {
            Transform trans;
            trans.position_.x = x;
            trans.position_.z = z;
            Model::SetTransform(hModel_[(x + z) % 5], trans);
            Model::Draw(hModel_[(x + z) % 5]);
        }
    }
}

//開放
void Stage::Release()
{
}