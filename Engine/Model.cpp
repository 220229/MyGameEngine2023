#include "Model.h"

int Model::Load(string _fileName)
{
	//モデルデータを設定
	ModelData* pData;
	pData = new ModelData;
	
	//モデル::ファイルネームを設定
	pData->fileName_ = _fileName;


	//モデル::ｆｂｘデータを設定
	
	
	for (auto e : modelList_) {
		if (e->fileName_ == _fileName){
			pData->fbx_ = e->fbx_;
			break;
		}
	}

	pData->fbx_ = nullptr;
	if (!pData->fbx_) {
		pData->fbx_ = new Fbx;
		pData->fbx_->Load(_fileName);
	}

	//モデルリストに追加
	modelList_.push_back(pData);

	//リスｔの何番目に追加されたのかを返す
	return (modelList_.size()-1);
}

void Model::SetTransform(int _hModel, Transform _transform)
{
	//トランスフォームを設定
	modelList_[_hModel]->transform_ = _transform;
}

void Model::Draw(int _hModel)
{
	//描画
	modelList_[_hModel]->fbx_->Draw(modelList_[_hModel]->transform_);
}
