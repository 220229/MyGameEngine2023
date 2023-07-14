#pragma once
#include <string>
#include <vector>

#include "Transform.h"
#include "Fbx.h"
using std::string;

namespace Model
{
	//////////////////////////////////////////
	struct  ModelData
	{
		string fileName_;
		Transform transform_;
		Fbx* fbx_;
	};
	std::vector<ModelData*> modelList_;

	//////////////////////////////////////////

	/// <summary>
	/// モデルの読み込み
	/// </summary>
	/// <param name="_fileName">ファイル名</param>
	/// <returns>モデルハンドル</returns>
	int Load(string _fileName);

	/// <summary>
	/// 変換行列を設定
	/// </summary>
	/// <param name="_hModel">モデルハンドル</param>
	/// <param name="_transform">変換行列</param>
	void SetTransform(int _hModel, Transform _transform);

	/// <summary>
	/// 描画
	/// </summary>
	/// <param name="_hModel">モデルハンドル</param>
	void Draw(int _hModel);

	//////////////////////////////////////////

}