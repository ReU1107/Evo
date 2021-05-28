#pragma once
#include "AlphaImpl.h"
#include "Array.h"
#include "Vector.h"

namespace Alpha
{
	/*
	*　スケルタルアニメーション　骨格
	*/
	class Joint;

	class Skeleton
	{
	public:
		// 
		Skeleton();
		// 
		~Skeleton();

		// 行列パレット取得
		const TArray<Vector3>& GetMatrixPallet() const;

		// ジョイント取得
		Joint* GetJoint(const char* name) const;

	private:
		AlphaImpl;

	};
}