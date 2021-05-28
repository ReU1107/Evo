#pragma once
#include "AlphaImpl.h"

namespace Alpha
{
	/*
	* 2D専用アニメーション
	* 複数のテクスチャをローカル空間内で線形変換(移動、回転、拡大縮小)を行うタイプのアニメーション
	* 名前を変更する可能性あり
	*/

	class SpriteAnimation
	{
	public:
		// 
		SpriteAnimation();
		// 
		~SpriteAnimation();
	private:
		AlphaImpl;


	};
}