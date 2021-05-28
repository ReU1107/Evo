#pragma once
#include "AlphaImpl.h"

namespace Alpha
{

	// 行列パレットの生成までは行う
	// それより先の処理は上位層での担当処理になる

	class SkeletalAnimation
	{
	public:
		// 
		SkeletalAnimation();
		// 
		~SkeletalAnimation();

		// 更新処理
		void Update();
		// 行列パレット取得
	private:
		AlphaImpl;
	};
}