#pragma once
#include "Type.h"
#include "Animation.h"
#include "AlphaImpl.h"

namespace Alpha
{
	/*
	* テクスチャを切り替えるタイプのアニメーション
	* 紙芝居をイメージするとわかりやすい
	*/
	// 一枚のテクスチャを縦、横に分割して表示する
	// マテリアルにくっつけるもの
	class Flipbook
	{
		uint32 m_rowCount;		// 行の数(縦方向の分割数)
		uint32 m_columnCount;		// 列の数(横方向の分割数)
		//Texture2DPtr m_texture;	// 
	};

	class FlipbookAnimation final : public Animation
	{
	public:
		FlipbookAnimation();
		~FlipbookAnimation();

	private:
		AlphaImpl;
	};

}
