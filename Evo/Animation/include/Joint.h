#pragma once
#include "AlphaImpl.h"
#include "Type.h"
#include "Matrix.h"

namespace Alpha
{

	class Joint
	{
	public:
		// 
		Joint();
		// 
		~Joint();

		// 親ジョイント追加
		void SetParent(Joint* parent);

		// 子ジョイント追加
		void AddChild(Joint* child);
		// 子ジョイント設定
		void SetChild(Joint* child, int32 index);

		// 初期姿勢行列設定
		void SetBindPose(const Matrix4x4& pose);

		// ワールド変換行列取得
		Matrix4x4 GetWorldMatrix() const;

		// ローカル変換行列取得
		Matrix4x4 GetLocalMatrix() const;

		// 行列パレット用行列取得
		Matrix4x4 GetProductMatrix() const;

	private:
		AlphaImpl;

	};
}