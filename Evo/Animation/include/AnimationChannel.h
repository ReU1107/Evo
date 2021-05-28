#pragma once
#include "AlphaImpl.h"

namespace Alpha
{
	// アニメーションカーブをグループ化したもの

	class AnimationChannel
	{
	public:
		AnimationChannel();
		~AnimationChannel();

	private:
		AlphaImpl;

	};

}