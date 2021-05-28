#include "AnimationClip.h"
#include "Check.h"
#include "AnimationChannel.h"
#include "AnimationCurve.h"

namespace Alpha
{
	/*
	* AnimationClip:アニメーション情報(キーフレーム配列の集まりを持ったものでしかない)
	* 単一のジョイントに対してのクリップ
	* 前回:アニメーションクリップがスケルトン単位だった
	*/

	// 動かすオブジェクト名とそれに伴う
	class AnimationClip::Impl
	{
	private:
		TArray<AnimationChannel*> m_channels;	// アニメーションチャンネル配列

		float m_blendCoeff;
	public:
		Impl();
		~Impl();
		// アニメーションチャンネル追加
		void AddAnimationChannel(AnimationChannel* channel);
		// ブレンド率設定
		void SetBlendCoeff(const float coeff);

	};


	AnimationClip::Impl::Impl()
	{

	}

	AnimationClip::Impl::~Impl()
	{

	}

	AnimationClip::AnimationClip()
		: m_impl(new Impl())
	{
	}

	AnimationClip::~AnimationClip()
	{
		delete m_impl;
	}
}