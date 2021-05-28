#pragma once
#include "Type.h"
#include "AlphaImpl.h"
#include "Keyframe.h"
#include "Array.h"

namespace Alpha
{

	// キーフレームの集合体
	class AnimationCurve
	{
	public:
		AnimationCurve() noexcept;
		// デストラクタ
		~AnimationCurve() noexcept;

		// キーフレーム数取得
		uint64 GetKeyframeCount() const;

		// ソート(タイム順)
		void Sort();
	private:
		AlphaImpl;

	};

}
